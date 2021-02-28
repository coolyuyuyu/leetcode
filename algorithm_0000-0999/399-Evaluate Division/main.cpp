class Solution {
public:
    struct Node {
        vector<pair<size_t, double>> neighbors;
    };

    struct Graph {
        vector<Node> nodes;
        unordered_map<string, size_t> indexMap;
    };

    Graph buildGraph(const vector<pair<string, string>>& equations, const vector<double>& values) {
        assert(equations.size() == values.size());

        Graph g;

        size_t num = equations.size();
        for (size_t i = 0; i < num; ++i) {
            const pair<string, string>& terminalPair = equations[i];
            size_t index1; {
                pair<unordered_map<string, size_t>::iterator, bool> p = g.indexMap.emplace(terminalPair.first, 0);
                if (p.second) {
                    g.nodes.emplace_back();
                    index1 = g.nodes.size() - 1;
                    p.first->second = index1;
                }
                else {
                    index1 = p.first->second;
                }
            }
            size_t index2; {
                pair<unordered_map<string, size_t>::iterator, bool> p = g.indexMap.emplace(terminalPair.second, 0);
                if (p.second) {
                    g.nodes.emplace_back();
                    index2 = g.nodes.size() - 1;
                    p.first->second = index2;
                }
                else {
                    index2 = p.first->second;
                }
            }
            g.nodes[index1].neighbors.emplace_back(index2, values[i]);
            g.nodes[index2].neighbors.emplace_back(index1, 1 / values[i]);
        }

        return g;
    }

    double calcResult(const Graph& g, const pair<string, string>& terminalPair) {
        size_t indexSrc; {
            unordered_map<string, size_t>::const_iterator itr = g.indexMap.find(terminalPair.first);
            if (itr == g.indexMap.end()) {
                return -1;
            }
            indexSrc = itr->second;
        }
        size_t indexDst; {
            unordered_map<string, size_t>::const_iterator itr = g.indexMap.find(terminalPair.second);
            if (itr == g.indexMap.end()) {
                return -1;
            }
            indexDst = itr->second;
        }

        vector<bool> visited(g.nodes.size(), false);
        visited[indexSrc] = true;

        struct Frame {
            Frame(size_t pfi, size_t ni, double c)
                : prevFrameIndex(pfi)
                , nodeIndex(ni)
                , cost(c) {
            }
            size_t prevFrameIndex;
            size_t nodeIndex;
            double cost;
        };

        vector<Frame> frames;
        frames.emplace_back(0, indexSrc, 1.0);
        size_t fIndex = 0;
        while (fIndex < frames.size()) {
            const Frame& frame = frames[fIndex];
            if (frame.nodeIndex == indexDst) {
                break;
            }

            const vector<pair<size_t, double>>& neighbors = g.nodes[frame.nodeIndex].neighbors;
            for (size_t i = 0; i < neighbors.size(); ++i) {
                size_t indexNbr = neighbors[i].first;
                if (visited[indexNbr]) {
                    continue;
                }
                double cost = neighbors[i].second;
                frames.emplace_back(fIndex, indexNbr, cost);
            }
            ++fIndex;
        }

        if (fIndex >= frames.size()) {
            return -1.0;
        }

        double costAll = 1.0;
        while (fIndex != 0) {
            costAll *= frames[fIndex].cost;
            fIndex = frames[fIndex].prevFrameIndex;
        }

        return costAll;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        Graph g = buildGraph(equations, values);

        vector<double> results;
        for (size_t i = 0; i < queries.size(); ++i) {
            results.emplace_back(calcResult(g, queries[i]));
        }

        return results;
    }
};
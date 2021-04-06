class Solution {
public:
    vector<int> rearrangeBarcodes_Heap(vector<int>& barcodes) {
        typedef pair<int, int> NumCount;
        auto comp = [](const NumCount& nc1, const NumCount& nc2) {
            return (nc1.second < nc2.second);
        };
        priority_queue<NumCount, vector<NumCount>, decltype(comp)> pq(comp); { // max_heap
            unordered_map<int, int> counts;
            for (int barcode : barcodes) {
                ++counts[barcode];
            }

            for (const auto& p : counts) {
                pq.push(p);
            }
        }

        for (size_t index = 0; !pq.empty(); pq.pop()) {
            const NumCount& nc = pq.top();
            for (int i = 0; i < nc.second; ++i) {
                if (barcodes.size() <= index) {
                    index = 1;
                }
                barcodes[index] = nc.first;
                index += 2;
            }
        }

        return barcodes;
    }

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        return rearrangeBarcodes_Heap(barcodes);
    }
};
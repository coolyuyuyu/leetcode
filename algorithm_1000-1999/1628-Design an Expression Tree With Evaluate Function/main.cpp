/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    Node()
        : pLft(nullptr)
        , pRht(nullptr) {
    }
    Node(Node* pLft_, Node* pRht_)
        : pLft(pLft_)
        , pRht(pRht_) {
    }

    virtual ~Node () {
        delete pLft;
        delete pRht;
    };

    virtual int evaluate() const = 0;

protected:
    // define your fields here
    Node* pLft;
    Node* pRht;
};

class NumberNode : public Node {
public:
    NumberNode(int val)
        : Node()
        , m_val(val) {
    }

    int evaluate() const {
        return m_val;
    }

private:
    int m_val;
};

template <template<class> class T>
class BinaryNode : public Node {
public:
    BinaryNode(Node* pLft, Node* pRht)
        : Node(pLft, pRht) {
    }

    int evaluate() const {
        return m_op(pLft->evaluate(), pRht->evaluate());
    }

private:
    T<int> m_op;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> stk;
        for (const string& token : postfix) {
            if ('0' <= token[0] && token[0] <= '9') {
                stk.push(new NumberNode(stoi(token)));
            }
            else {
                Node* pRht = stk.top();
                stk.pop();
                Node* pLft = stk.top();
                stk.pop();
                if (token == "+") {
                    stk.push(new BinaryNode<plus>(pLft, pRht));
                }
                else if (token == "-") {
                    stk.push(new BinaryNode<minus>(pLft, pRht));
                }
                else if (token == "*") {
                    stk.push(new BinaryNode<multiplies>(pLft, pRht));
                }
                else if (token == "/") {
                    stk.push(new BinaryNode<divides>(pLft, pRht));
                }
                else {
                    assert(false);
                }
            }
        }
        assert(stk.size() == 1);

        return stk.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
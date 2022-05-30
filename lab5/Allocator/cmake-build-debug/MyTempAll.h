#include <map>
#include <memory>



template<typename T>
class MyTempAll{
public:
    MyTempAll(std::map<unsigned int,unsigned int>::const_iterator begin,std::map<unsigned int, unsigned int>::const_iterator end):begin(begin),end(end){
        int counter = 0;
        while(begin!=end){
            if(begin->first!=0 && begin->second != 0) {
                memoryDiv.insert(begin->first, createList(begin->first, begin->second))
                ++counter;
            } else{
                throw std::invalid_argument;
            }
            begin++;
        }
    }



private:
    struct Node {
        std::shared_ptr<T> pointer = nullptr;
        Node *next;
        int mustBe = 0;
        int counter = 0;
        std::size_t size = 0;
    };

    struct list {
        std::shared_ptr<Node> first = nullptr;
        std::shared_ptr<Node> last = nullptr;


        [[nodiscard]] bool isEmpty() const {
            return first == nullptr;
        }

        void add(T &value) {
            std::shared_ptr<Node> pointer = new Node<T>;
            if (isEmpty()) {
                first = value.pointer;
                last = value.pointer;
                return;
            }
            last->next = value.pointer;
            last = value.pointer;
        }
    };

    std::map<unsigned int, unsigned int>::const_iterator begin;
    std::map<unsigned int, unsigned int>::const_iterator end;
    std::map<unsigned int, list> memoryDiv;

    list createList(int size, int amount){
        list l = new list;
        for (int i = 0; i < amount; ++i) {
            Node chunk = new Node;
            chunk.pointer = new size;
            chunk.size = size;
            chunk.mustBe = amount;
            l.add(chunk);
        }
        return l;
    }


};




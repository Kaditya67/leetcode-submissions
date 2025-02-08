class NumberContainers {
public:
    //Space : O(n)
    unordered_map<int, int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

    NumberContainers() {
        //do nothing    
    }
    
    void change(int index, int number) {
        idxToNum[index] = number; //O(1)

        numToIdx[number].push(index); //O(log(n))
    }
    
    int find(int number) {
        if(!numToIdx.count(number)) {
            return -1;
        }

        auto& pq = numToIdx[number];

        while(!pq.empty()) { //O(k * logn)
            int idx = pq.top(); //O(1)

            if(idxToNum[idx] == number) {
                return idx;
            }

            pq.pop(); //O(log(n))
        }

        return -1;
    }
};
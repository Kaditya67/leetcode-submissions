class ProductOfNumbers {
public:
    vector<int> prefixPrd;
    ProductOfNumbers() {
        prefixPrd.push_back(1);
    }
    void add(int num) {
        if (num == 0) {
            prefixPrd.clear();
            prefixPrd.push_back(1);
        } else {
            prefixPrd.push_back(num * prefixPrd.back());
        }
    }
    int getProduct(int k) {
        int size = prefixPrd.size();
        if (k >= size) return 0;
        return prefixPrd.back() / prefixPrd[size - k - 1];
    }
};
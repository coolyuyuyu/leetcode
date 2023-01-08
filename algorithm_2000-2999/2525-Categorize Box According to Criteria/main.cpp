class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volumn = (long long)(length) * (long long)(width) * (long long)(height);

        bool isBulky = false;
        if ((length>= 1e4 ||width >= 1e4 || height >= 1e4) || volumn >= 1e9) {
            isBulky = true;
        }

        bool isHeavy = mass >= 100;

        string type;
        if (isBulky && isHeavy) {
            type = "Both";
        }
        else if (!isBulky && !isHeavy){
            type = "Neither";
        }
        else if (isBulky && !isHeavy) {
            type = "Bulky";
        }
        else if (!isBulky && isHeavy) {
            type = "Heavy";
        }

        return type;
    }
};

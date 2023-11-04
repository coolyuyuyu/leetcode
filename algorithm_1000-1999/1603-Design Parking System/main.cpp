class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small)
        : m_cntB(big)
        , m_cntM(medium)
        , m_cntS(small) {
    }

    bool addCar(int carType) {
        switch (carType) {
        case 1:
            if (m_cntB-- <= 0) {
                return false;
            }
            break;
        case 2:
            if (m_cntM-- <= 0) {
                return false;
            }
            break;
        case 3:
            if (m_cntS-- <= 0) {
                return false;
            }
            break;
        }

        return true;
    }

private:
    int m_cntB;
    int m_cntM;
    int m_cntS;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

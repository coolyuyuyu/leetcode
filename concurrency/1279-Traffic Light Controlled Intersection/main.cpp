class TrafficLight {
private:
    int m_light;
    mutex m_mtx;

public:
    TrafficLight()
        : m_light(1) {
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        unique_lock lck(m_mtx);

        if (m_light != roadId) {
            m_light = roadId;
            turnGreen();
        }
        crossCar();
    }
};
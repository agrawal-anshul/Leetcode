class Solution {
    struct Car {
        int x;      // position
        double t;   // time to reach target

        Car(int x, double t) {
            this->x = x;
            this->t = t;
        }
    };

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<Car> cars;

        // Step 1: Compute time to reach target and store it
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back(Car(position[i], time));
        }

        // Step 2: Sort cars by starting position in descending order
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.x > b.x;
        });

        int fleet = 0;
        double lastTime = 0.0;

        for (int i = 0; i < n; i++) {
            if (cars[i].t > lastTime) {
                // This car doesn't catch up to the previous one
                fleet++;
                lastTime = cars[i].t;
            }
        }

        return fleet;
    }
};


//         target   = 12
//         position = [10,8,0,5,3]
// distanceToTarget = [2,4,12,7,9]
//         speed    = [2,4,1,1,3]
//         time(hr) = [1,1,12,7,0.33]

// Sort the positon array decreasing order:
//         target   = 12
//         position = [10,8,5,3,0]
// distanceToTarget = [2,4,7,9,12]
//         speed    = [2,4,1,3,1]
//         time(hr) = [1,1,7,0.33,12]
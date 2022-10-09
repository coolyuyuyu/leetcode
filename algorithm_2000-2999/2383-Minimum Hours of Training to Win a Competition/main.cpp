class Solution {
public:
    int minNumberOfHours(int energy, int experience, vector<int>& energies, vector<int>& experiences) {
        int hours = 0;
        for (size_t i = 0; i < energies.size(); ++i) {
            if (energy <= energies[i]) {
                hours += (energies[i] - energy + 1);
                energy = 1;
            }
            else {
                energy -= energies[i];
            }

            if (experience <= experiences[i]) {
                int diff = (experiences[i] - experience + 1);
                hours += diff;
                experience += diff;
            }
            experience += experiences[i];
        }

        return hours;
    }
};

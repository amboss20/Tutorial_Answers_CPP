#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SPowerData {
    float m_Amp;
    float m_Res;
    float m_Power;
};

class CPowerInfo {
private:
    SPowerData *m_power_array;
    int m_numElements;
    fstream m_File;

public:
    // Constructor & Destructor
    CPowerInfo() : m_power_array(nullptr), m_numElements(0) {}
    ~CPowerInfo() {
        delete[] m_power_array;
    }


    int getNumElements(string pFile) {
        int count = 0;
        float d1, d2;
        m_File.open(pFile);
        while (m_File >> d1 >> d2)
            count++;
        m_File.close();
        return count;
    }

    
    void LoadData(string pFile, int numElements) {
        m_numElements = numElements;
        m_power_array = new SPowerData[numElements];

        m_File.open(pFile);
        for (int i = 0; i < numElements; i++) {
            m_File >> m_power_array[i].m_Amp;
            m_File >> m_power_array[i].m_Res;

            // Power (W) = I^2 * R
            m_power_array[i].m_Power = m_power_array[i].m_Amp
                                     * m_power_array[i].m_Amp
                                     * m_power_array[i].m_Res;
        }
        m_File.close();
    }

    
    void FindMinMaxPower(float &outMinPower, float &outMaxPower) {
        if (m_numElements == 0) return;

        outMinPower = m_power_array[0].m_Power;
        outMaxPower = m_power_array[0].m_Power;

        for (int i = 1; i < m_numElements; i++) {
            if (m_power_array[i].m_Power < outMinPower)
                outMinPower = m_power_array[i].m_Power;
            if (m_power_array[i].m_Power > outMaxPower)
                outMaxPower = m_power_array[i].m_Power;
        }
    }
};

int main() {
    CPowerInfo pw;
    int numElements = pw.getNumElements("AmpRes.txt");
    pw.LoadData("AmpRes.txt", numElements);

    float minpower, maxpower;
    pw.FindMinMaxPower(minpower, maxpower);

    cout << "\n The minimum power = " << minpower;
    cout << "\n The maximum power = " << maxpower;
    cout << endl;

    return 1;
}
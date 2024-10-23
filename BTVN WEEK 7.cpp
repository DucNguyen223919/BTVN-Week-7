#include <iostream>
using namespace std;
void findMaxMinYears(int years[], int population[], int N) {
    int maxPopulation = population[0], minPopulation = population[0];
    int maxYears[100], minYears[100];
    int maxCount = 0, minCount = 0;
	for (int i = 1; i < N; i++) {
        if (population[i] > maxPopulation) {
            maxPopulation = population[i]; 
            maxCount = 0;  
        }
        if (population[i] == maxPopulation) {
            maxYears[maxCount++] = years[i];
        }
        if (population[i] < minPopulation) {
            minPopulation = population[i]; 
            minCount = 0; 
        }
        if (population[i] == minPopulation) {
            minYears[minCount++] = years[i]; 
        }
    }
	cout << "Nhung nam co so luong nguoi sinh ra max (" << maxPopulation << " nguoi): ";
	for (int i = 0; i < maxCount; i++) {
        cout << maxYears[i] << " ";
    }
    cout << endl;
	cout << "Nhung nam co so luong nguoi sinh ra min (" << minPopulation << " nguoi): ";
    for (int i = 0; i < minCount; i++) {
        cout << minYears[i] << " ";
    }
    cout << endl;
}
void countSamePopulationYears(int population[], int N) {
    int count[100] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (population[i] == population[j]) {
                count[i]++;
            }
        }
    }
    cout << "So lan cac nam co cung so nguoi sinh ra" << endl;
    for (int i = 0; i < N; i++) {
        if (count[i] > 0) {
            cout << "So luong " << population[i] << " nguoi sinh ra co " << count[i] + 1 << " cung nam" << endl;
        }
    }
}
int main() {
    int N;
    cout << "Nhap so luong nam: ";
    cin >> N;
    int nam[100], dan_so[100];
    for (int i = 0; i < N; i++) {
        cout << "Nhap nam thu " << i + 1 << ": ";
        cin >> nam[i];
        cout << "Nhap so luong nguoi sinh ra trong nam " << nam[i] << ": ";
        cin >> dan_so[i];
    }
    findMaxMinYears(nam,dan_so,N);
    countSamePopulationYears(dan_so,N);
    return 0;
}

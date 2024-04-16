#include <iostream>
#include <string>

using namespace std;

class Horse {
protected:
    string breed;
    char gender;
    int age;

public:
    Horse(string _breed, char _gender, int _age) : breed(_breed), gender(_gender), age(_age) {}
        
    void display() {
        cout << "Breed: " << breed << '\n';
        cout << "Gender: " << gender << '\n';
        cout << "Age: " << age << '\n';
    }
};

class Race : public Horse {
private:
    int number;
    string track;
    float time;

public:
    Race(string _breed, char _gender, int _age, int _number, string _track, float _time)
        : Horse(_breed, _gender, _age), number(_number), track(_track), time(_time) {}

    void display() {
        Horse::display();
        cout << "Race Number: " << number << '\n';
        cout << "Track: " << track << '\n';
        cout << "Time: " << time << '\n';
    }
};

int main() {
    Race race("SABAKA", 'M', 5, 101, "Ternopil", 13.35);

    race.display();

}

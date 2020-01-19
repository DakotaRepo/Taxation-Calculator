#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

void Taxation();
void PhaseOne();
void PhaseTwo();
void PhaseThree();
void PhaseFinal();
int userIncome;
int userTaxes = 0;
int userTaxExemption = 0;

int main(){
    Taxation();
    return 0;
}

void PhaseOne(){
    userTaxExemption = 10000;
    userIncome = userIncome - 10000;
    userTaxes = userIncome * .10;
    userIncome = userIncome * .90;
}
void PhaseTwo(){
    userTaxExemption = userTaxExemption + 20000;
    userIncome = userIncome - 20000;
    userTaxes = userTaxes + (userIncome * .25);
    userIncome = userIncome * .75;
}
void PhaseThree(){
    userTaxExemption = userTaxExemption + 70000;
    userIncome = userIncome - 70000;
    userTaxes = userTaxes + (userIncome * .40);
    userIncome = userIncome * .60;
}
void PhaseFinal(){
    userIncome = userIncome + userTaxExemption;
    std::cout << "Your total taxation is: " << userTaxes << "\nYour income after taxes is: " << userIncome;
}
void Taxation(){
    std::cout << "Enter your income\n";
    std::cin >> userIncome;
     if(userIncome > 10000 && userIncome <= 30000){
        PhaseOne();
        PhaseFinal();
    } else if(userIncome > 30000 && userIncome <= 100000){
        PhaseOne();
        PhaseTwo();
        PhaseFinal();
    } else if(userIncome > 100000){
        PhaseOne();
        PhaseTwo();
        PhaseThree();
        PhaseFinal();
    } else PhaseFinal();
}
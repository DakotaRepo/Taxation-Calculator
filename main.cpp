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
int userTaxExcemption = 0;
int sumTotal;

int main(){
    Taxation();
    return 0;
}

void PhaseOne(){
    if(userIncome > 30000){
        userTaxes = 2000;
    }else {
    userTaxExcemption = 10000;
    userIncome -= 10000;
    userTaxes = userIncome * .10;
    userIncome *= .90;
    }
}
void PhaseTwo(){
    if (userIncome > 100000){
        userTaxes = 19500;
    }else{
    userTaxExcemption = 28000;
    userIncome -= 30000;
    userTaxes += userIncome * .25;
    userIncome *= .75;
    }
}
void PhaseThree(){
    userTaxExcemption = 80500;
    userIncome -= 100000;
    userTaxes += userIncome * .40;
    userIncome *= .60;
}
void PhaseFinal(){
    userIncome += userTaxExcemption;
    if(userIncome + userTaxes < sumTotal) userIncome ++;
    std::cout << "Your total taxation is: " << userTaxes << "\nYour income after taxes is: " << userIncome;
}
void Taxation(){
    std::cout << "Enter your income\n";
    std::cin >> sumTotal;
    userIncome = sumTotal;
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
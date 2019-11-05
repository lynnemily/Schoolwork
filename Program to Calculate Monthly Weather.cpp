//Program to Calculate Monthly Weather



#include <iostream>
#include <iomanip>

using namespace std;

float getTemp ();


struct weather
{
    float monthlyRain;
    float highTemp;
    float lowTemp;
    float monthlyTemp;
    
};

int main()
{
    weather month[12];
    float totalRain = 0;
    float averRain = 0;
    float averTemp;
    float totalTemp = 0;
    int lowestMonth = 0;
    int highestMonth = 0;


    cout<< "Enter in the following information: "<<endl;
    cout <<endl << endl;

    for(int count = 0;count < 12;count++)
    {
        cout<< "Month " << (count + 1)<<" :"<< endl;

        cout<< "    Total rainfall: "<<endl;
        cin>> month[count].monthlyRain;

        cout<< "    High Temperature: "<<endl;
        month[count].highTemp = getTemp();
        cout<< "    Low Temperature: "<<endl;
        month[count].lowTemp = getTemp();
        
        if ( month[count].lowTemp < month[lowestMonth].lowTemp)
            lowestMonth = count;
        if (month[count].highTemp > month[highestMonth].highTemp)
            highestMonth = count;        
       
        totalRain = month[count].monthlyRain + totalRain;
        month[count].monthlyTemp = (month[count].highTemp + month[count].lowTemp)/2;
        totalTemp = month[count].monthlyTemp + totalTemp;
        
        cout <<endl;
    }
    
        averTemp = totalTemp/12;
        averRain = totalRain/12;
       
    cout<< "Total Rainfall for the year: ";      
    cout<<  totalRain<<endl;
    
    cout<< "Average Monthly Rain: ";
    cout<< averRain<< endl;
    
    cout<< "Average Monthly Average Temperature :";
    cout<< averTemp<< endl;
    
    cout<< "Highest Temperature: ";
    cout<< month[highestMonth].highTemp << " (Month " << (highestMonth+1) << ")"<<endl;
    
    cout<< "Lowest Temperature: ";
    cout<< month[lowestMonth].lowTemp << " (Month " << (lowestMonth+1) << ")"<<endl;  
    
    


return 0;
}


float getTemp()
{
    float temp;
    cin>>temp;
    while (temp < -100 || temp > 140)
    {
    cout<< "Please enter a temperature between -100 and 140: ";
    cin>> temp;
    }
    return temp;
}


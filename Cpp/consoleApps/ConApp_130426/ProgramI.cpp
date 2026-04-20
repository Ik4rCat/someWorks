#include <vector>
#include <string>
//#include <algorithm>

double calculate(std::vector<double> data, std::string type) 
{
    
    double result = 0.0;
    
    if (type == "sum") 
    {
        for (int i = 0; i < data.size(); i++) 
        {
            result = result + data[i];
        }
    } 
    else if (type == "avg") 
    {
        double sum = 0.0;
        
        for (int i = 0; i < data.size(); i++)
        {
            sum = sum + data[i];
        }
        
        if (data.size() > 0) result = sum / data.size();
    } 
    else if (type == "max") 
    {
        if (data.size() > 0) 
        {
            result = data[0];
            
            for (int i = 1; i < data.size(); i++) 
            {
                if (data[i] > result) result = data[i];
            }
        }
    } 
    else if (type == "min")
    {
        if (data.size() > 0) 
        {
            result = data[0];
            
            for (int i = 1; i < data.size(); i++)
            {
                if (data[i] < result) result = data[i];
            }
        }
    }
    return result;
}
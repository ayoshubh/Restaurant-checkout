/**
 * @file Administrator.cpp
 * @author Shubham Chauhan
 * @brief This file contains implementation for Administrator class where functionalities of administrator are defined.
 * @version 0.1
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Administrator.h"

/**
 * @brief Construct a new Administrator:: Administrator object. 
 * The data members username and password are initialised in the constructor.
 */
Administrator::Administrator()
{
    std::ifstream file("TextFiles/AdminCredential.txt");
    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    int strCount = 0;
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i] == '\n')
        {
            strCount = i;
            break;
        }
        this->username += content[i];
    }

    for (int i = strCount + 1; i < content.size(); i++)
    {
        this->password += content[i];
    }
}

/**
 * @brief This is a getter method that is used to fetch username.
 * 
 * @return std::string 
 */
std::string Administrator::getUsername()
{
    return username;
}

/**
 * @brief This is a getter method that is used to fetch password.
 * 
 * @return std::string 
 */
std::string Administrator::getPassword()
{
    return password;
}

/**
 * @brief This method returns the transactions done on a particular date.
 * 
 * @param date
 * @param month
 * @param year
 * @return std::string 
 */
std::string Administrator::getLogbook(std::string date, std::string month, std::string year)
{
    try
    {
        std::string fileN = "TextFiles/DatedReceiptFiles/ReceiptFile:" + date + "-" + month + "-" + year + ".txt";
        std::ifstream file(fileN);

        std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        return content;
    }
    catch (const std::ios_base::failure &e)
    {
        // Handle file I/O exception
        std::cerr << "File I/O exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

/**
 * @brief This method returns the total revenue generated by the restaurant.
 * 
 * @return int 
 */
int Administrator::totalRevenue(std::string month, std::string year)
{
    try
    {
        std::ifstream inputFile;
        
        if(month==""){
            inputFile.open("TextFiles/RevenueFiles/RevenueOf:"+year+".txt", std::ios::in);
        }else{
            inputFile.open("TextFiles/RevenueFiles/RevenueOf:"+month+"-"+year+".txt", std::ios::in);
        }
        

        if (!inputFile.is_open())
        {
            std::cerr << "Unable to open the file." << std::endl;
            return -1; // Return an error code
        }

        int number;
        int sum = 0;
        while (inputFile >> number)
        {
            sum += number;
        }

        inputFile.close();
        return sum;
    }
    catch (const std::ios_base::failure &e)
    {
        // Handle file I/O exception
        std::cerr << "File I/O exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

/**
 * @brief This method returns the average rating scored by the restaurant.
 * 
 * @return float 
 */
float Administrator::avgRating()
{
    try
    {
        std::ifstream inputFile("TextFiles/RatingFile.txt"); // Assuming the file is named "RatingFile.txt"

        if (!inputFile.is_open())
        {
            std::cerr << "Unable to open the file." << std::endl;
            return -1.0f; // Return an error code
        }

        float number;
        float sum = 0.0f;
        float count = 0.0f;

        while (inputFile >> number)
        {
            sum += number;
            count += 1.0f;
        }

        float avg = sum / count;
        inputFile.close();
        return avg;
    }
    catch (const std::ios_base::failure &e)
    {
        // Handle file I/O exception
        std::cerr << "File I/O exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}

std::string Administrator::getFeedback(){
        std::ifstream file("TextFiles/Feedback.txt");

        std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        return content;
    }

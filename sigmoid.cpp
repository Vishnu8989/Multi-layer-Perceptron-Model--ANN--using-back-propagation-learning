#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
float weight[13];
float lr = 1;
float bias = 1;
void get_random(float d[], int n)
{
    srand((unsigned int)time(NULL));
    int a = 1.0;
    for (int i = 0; i < n; i++)
    {
        d[i] = (float(rand()) / float((RAND_MAX)) * a);
    }
}
void arrayDisplay(float *d, int a)
{
    printf("\nPrinting The Weights : ");
    for (int i = 0; i < a; i++)
    {
        printf("\narr[%d] : ", i);
        printf("%f", d[i]);
    }
}
void final_chech(int data1[])
{
    cout << "\n-------------------------------\n";
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", data1[k++]);
        }
        printf("\n");
    }
    float output = (bias * weight[12]);
    for (int i = 0; i < 12; i++)
    {
        output = output + (data1[i] * weight[i]);
    }
    output = 1 / (1 + exp(-1 * output));
    cout << "\nPerceptron Output: " << output << endl;
    if (output < .5)
    {
        output = 0;
    }
    else
    {
        output = 1;
    }
    cout << "\nFinal Prediction: " << output << endl;
}
void trainning(int inputs[], int result)
{
    float output = (bias * weight[12]);
    for (int i = 0; i < 12; i++)
    {
        output = output + (inputs[i] * weight[i]);
    }
    float prediction = 1 / (1 + exp(-1 * output));
    float error = result - prediction;
    for (int i = 0; i < 12; i++)
    {
        weight[i] = weight[i] + (error * inputs[i] * lr);
    }
    weight[12] = weight[12] + (error * bias * lr);
    // cout << "\n-------------------------------\n\n";
    // cout << "Output : " << output << '\n';
    // cout << "Prediction : " << prediction << endl;
    // cout << "error : " << error << endl;
    // arrayDisplay(weight, 13);
}

int main()
{

    system("cls");
    get_random(weight, 13);
    cout << "Before Trainning\n";
    arrayDisplay(weight, 13);
    int data1[12] = {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1}; // l
    int res_1 = 1;
    int data2[12] = {1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0}; // T
    int res_2 = 1;
    int data3[12] = {1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0}; // random
    int data4[12] = {1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0}; // 1
    int res_4 = 1;
    int data5[12] = {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}; // O
    int res_5 = 0;
    for (int i = 0; i < 50; i++) // Trainning
    {
        trainning(data1, res_1);
        trainning(data2, res_2);
        trainning(data4, res_4);
        trainning(data5, res_5);
    };
    cout << "\n-------------------------------\n\n";
    cout << "After training\n";
    arrayDisplay(weight, 13);
    final_chech(data1);
    final_chech(data2);
    final_chech(data3);
    final_chech(data4);
    final_chech(data5);
}
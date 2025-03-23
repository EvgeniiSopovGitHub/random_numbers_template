#pragma once

#include <random>
#include <vector>

using namespace std;

int random_int(int lower, int upper);
double random_uniform(double minimal, double maximal);
double random_normal(double loc, double scale);
double random_cauchy(double loc, double scale);
double random_laplace(double loc, double scale);
double random_student(double loc, double scale, double df);
double random_logistic(double loc, double scale);

// set a seed for a starting point for generators
random_device rd;
size_t seed = rd();

// use a fixed seed
// seed = 0

// shift all generators
mt19937 generator_uni_i(seed);
mt19937 generator_uni_r(seed + 100);
mt19937 generator_norm(seed + 200);
mt19937 generator_cauchy(seed + 300);
mt19937 generator_laplace(seed + 400);
mt19937 generator_student(seed + 500);
mt19937 generator_logistic(seed + 600);
mt19937 generator_uni_i_2(seed + 700);

// different generators
uniform_int_distribution<int> uni_int(0, 32768);
uniform_real_distribution<double> uni_real(0.0, 1.0);
normal_distribution<double> norm_dist(0.0, 1.0);
cauchy_distribution<double> cauchy_dist(0.0, 1.0);
student_t_distribution<double> t_df2_dist(2);
student_t_distribution<double> t_df5_dist(5);


// high-level functions
// random integers
int random_int(int lower, int upper)
{
    if (lower > upper)
        return 0;
    else 
        return lower + uni_int(generator_uni_i) % (upper - lower + 1);
}
// random uniform
double random_uniform(double minimal, double maximal)
{
    return uni_real(generator_uni_r) * (maximal - minimal) + minimal;
}
// random normal
double random_normal(double loc, double scale)
{
    return norm_dist(generator_norm) * scale + loc;
}
// random Cauchy
double random_cauchy(double loc, double scale)
{
    return cauchy_dist(generator_cauchy) * scale + loc;
}
// random Laplace
double random_laplace(double loc, double scale)
{
    double u = uni_real(generator_laplace);
    return (loc - scale * copysign(1.0, u - 0.5) * log(1 - 2 * abs(u - 0.5)));
}
// random t-dist Student with df=2, df=5
double random_student(double loc, double scale, double df)
{
    double tSample = 0.0;
    if(df == 2)
        tSample = t_df2_dist(generator_student);
    else if (df == 5)
        tSample = t_df5_dist(generator_student);
    // Apply location and scale transformation
    return loc + scale * tSample;
}
// random logistic
double random_logistic(double loc, double scale)
{
    double u = uni_real(generator_logistic);
    return loc + scale * log(u / (1.0 - u));
}
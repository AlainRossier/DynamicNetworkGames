#include <iostream>
#include <vector>
#include <stdio.h>

#include "model.h"

extern size_t NPLAYERS ;
extern std::vector<size_t> z ;
extern std::vector<std::vector<int> > adj ;
extern std::vector<std::vector<std::vector<size_t> > > neigh ;

using namespace std ;

int main() {
	vector<vector<vector<double> > > probaindiv = {
		{
	{0.5,0.25,0.25},
	{0.5,0.25,0.25},
	{0.5,0.25,0.25},
	{0.5,0.25,0.25},
	{0.5,0.25,0.25},
	{0.5,0.25,0.25},
	{0.5,0.25,0.25},
	{0.5,0.25,0.25}
		},
			{
	{0.25,0.5,0.25},
	{0.25,0.5,0.25},
	{0.25,0.5,0.25},
	{0.25,0.5,0.25},
	{0.25,0.5,0.25},
	{0.25,0.5,0.25},
	{0.25,0.5,0.25},
	{0.25,0.5,0.25}
	
		},
			{
	{0.25,0.25,0.5},
	{0.25,0.25,0.5},
	{0.25,0.25,0.5},
	{0.25,0.25,0.5},
	{0.25,0.25,0.5},
	{0.25,0.25,0.5},
	{0.25,0.25,0.5},
	{0.25,0.25,0.5}
		}
		
	} ;

	vector<double> delta = {0.9,0.9,0.9} ;

	vector<vector<double> > initpayoff = {
		{4,3,3,1,0,-1,2,0},
		{4,1,3,3,-1,2,0,0},
		{4,3,1,3,2,0,-1,0}
		} ;
	
	//cout << calc_partial_derivative(delta, initpayoff, probaindiv, 3, 2, 1, 10) << endl ;

	initprobaindiv(probaindiv) ;
	cout << probaindiv << endl ;
	optimizer_step(delta, initpayoff, probaindiv, 10, 0.01) ;
	cout << probaindiv << endl ;

	return 0 ;
}

#include <iostream>
#include <vector>
#include <cstdlib> 

#include <stdio.h>
#include "global.h"

using namespace std ;

size_t NPLAYERS=3 ;

std::vector<size_t> z = {NPLAYERS,NPLAYERS} ;

//adjacency matrix : a_kl = 1 if k->l by winning an edge, -1 if losing an edge, 0 if unreachable in 1 move.
std::vector<std::vector<int> > adj = {
	{0,-1,-1,-1,0,0,0,0},
	{1,0,0,0,-1,-1,0,0},
	{1,0,0,0,-1,0,-1,0},
	{1,0,0,0,0,-1,-1,0},
	{0,1,1,0,0,0,0,-1},
	{0,1,0,1,0,0,0,-1},
	{0,0,1,1,0,0,0,-1},
	{0,0,0,0,1,1,1,0}

} ;
// neighbouring matrix ; n_kl tells you what are the players involved in the change of network.
std::vector<std::vector<std::vector<size_t> > > neigh = {
	{z,{0,2},{0,1},{1,2},z,z,z,z},
	{{0,2},z,z,z,{0,1},{1,2},z,z},
	{{0,1},z,z,z,{0,2},z,{1,2},z},
	{{1,2},z,z,z,z,{0,2},{0,1},z},
	{z,{0,1},{0,2},z,z,z,z,{1,2}},
	{z,{1,2},z,{0,2},z,z,z,{0,1}},
	{z,z,{1,2},{0,1},z,z,z,{0,2}},
	{z,z,z,z,{1,2},{0,1},{0,2},z}

} ;

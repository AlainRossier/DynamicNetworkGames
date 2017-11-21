#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <algorithm>    // std::random_shuffle

#include <stdio.h>
//#include "global.h"
#include "model.h"


using namespace std ;

extern size_t NPLAYERS ;
extern std::vector<size_t> z ;
extern std::vector<std::vector<int> > adj ;
extern std::vector<std::vector<std::vector<size_t> > > neigh ;


// return the networks to which player i can reach from network g
vector<size_t> getneigh(size_t i, size_t g) {
	vector<size_t> res(0) ;
	if(g<0 or g>neigh.size()-1) {
		cout << "This is not a network." << endl ;
		return res ;
	}
	else {
		res.push_back(g) ;
		for(size_t h(0);h<neigh.size();++h) {
			if(neigh[g][h][0]==i or neigh[g][h][1]==i) {
				res.push_back(h) ;
			}
		}
	return res ;
	}
	
}

// get the other player involved in going from network g to network h
size_t getplayer(size_t i, size_t g, size_t h) {
	if(neigh[g][h][0]==i) {
		return neigh[g][h][1] ;
	}
	else if(neigh[g][h][1]==i) {
		return neigh[g][h][0] ;
	}
	else if(g==h) {
		return i ;
	}
	else {
		cout << "This player doesn't exist (getplayer)" << endl ;
		return NPLAYERS ;
	}
	
}

size_t neigh_network(size_t g, size_t i, size_t j) {
	if(i > j) {
		size_t temp(i) ;
		i = j ;
		j = temp ;
	}
	else if(i == j) {
		return g ;
	}

	for(size_t h(0);h<neigh[g].size();h++) {
		if(neigh[g][h][0] == i and neigh[g][h][1] == j) {
			return h ;
		}
	}
}

bool is_network(size_t g, size_t i, size_t j) {
	if(i > j) {
		size_t temp(i) ;
		i = j ;
		j = temp ;
	}
	else if(i == j) {
		cout << "ERR : The players must be different." << endl ;
		return false ;
	}

	for(size_t h(0);h<neigh[g].size();h++) {
		if(neigh[g][h][0] == i and neigh[g][h][1] == j) {
			if(adj[g][h] == 1) {return false ;}
			else if(adj[g][h] == -1) {return true ;}
			else {cout << "ERR : Wrong set-up, check again" << endl ;}
		}
	}
}

vector<vector<double> > id(size_t n) {
	vector<vector<double> > res(n, vector<double>(n)) ;
	for(size_t i(0);i<n;i++) {
		res[i][i]=1 ;
	}
	return res ;
}

std::ostream& operator<<(std::ostream& os, std::vector<double> const& v) {
  os << "(" ;
  for(size_t n(0); n<v.size()-1; n++) {
    os << v[n] << "; " ; 
  }
      os << v[v.size()-1] << ")" << endl ;
      return os ;
}

ostream& operator<<(ostream& os, vector<vector<double> > const& v) {
	for(size_t i(0); i<v.size();i++) {
		for(size_t j(0); j<v[0].size();j++) {
		os << v[i][j] << " " ; 	
		}
	os << endl ;
	}
	return os ;
}

ostream& operator<<(ostream& os, std::vector<std::vector<std::vector<double> > > const& v) {
	for(size_t i(0); i<v.size(); i++) {
		os << i << "th player" << endl ;
		os << v[i] << endl ;
	}
	return os ;
}

ostream& operator<<(ostream& os, vector<vector<size_t> > const& v) {
	for(size_t i(0); i<v.size();i++) {
		for(size_t j(0); j<v[0].size();j++) {
		os << v[i][j] << " " ; 	
		}
	os << endl ;
	}
	return os ;
}

vector<vector<double> > operator+(vector<vector<double> > A, vector<vector<double> > B) {
	if(A.size()!=B.size() or A[0].size()!=B[0].size()) {
		cout << "Check the sizes of your matrices !" << endl ;
		return vector<vector<double> >(0) ;
	}
	else {
		vector<vector<double> > C(A.size(), vector<double>(A[0].size(), 0)) ;
		for(size_t i(0);i<C.size();i++) {
			for(size_t j(0);j<C[0].size();j++) {
				C[i][j]=A[i][j]+B[i][j] ;
			}
		}
	return C ;	
	}
	
}

vector<double> operator*(double const& r, vector<double> a) {
  vector<double> res(a.size()) ;
  for(size_t n(0); n<a.size(); n++) {
    res[n]=r*a[n] ; 
  }
  return res ; 
}

vector<vector<double> > operator*(double const& r, vector<vector<double> > A) {
	vector<vector<double> > B(A.size(), vector<double>(A[0].size(), 0)) ;
	for(size_t i(0);i<B.size();i++) {
			for(size_t j(0);j<B[0].size();j++) {
				B[i][j]=r*A[i][j] ;
			}
		}
	return B ;	
}

double scalar_prod(std::vector<double> a, std::vector<double> b) {
	double res(0) ;
	if(a.size() != b.size()) {
		cout << "ERR : Check the sizes of your vectors" << endl ;
	}
	else {
		for(size_t k(0); k<a.size(); k++) {
			res += a[k]*b[k] ;
		}
	}
	return res ;
}

double norm(std::vector<double> a) {
  double res(0) ;
  for(size_t n(0); n < a.size(); n++) {
    res += a[n]*a[n] ;
  }
  return sqrt(res);
}

vector<vector<double> > matmul(vector<vector<double> > A, vector<vector<double> > B) {
	if(A[0].size()!=B.size()) {
		cout << "Check the sizes of your matrices !" << endl ;
		return vector<vector<double> >(0) ;
	}
	else {
		vector<vector<double> > C(A.size(), vector<double>(B[0].size(), 0)) ;
		for(size_t i(0);i<C.size();i++) {
			for(size_t j(0);j<C[0].size();j++) {
				double entry(0) ;
				for(size_t k(0);k<B.size();k++) {
					entry+=A[i][k]*B[k][j] ;
				}
				C[i][j]=entry ;
			}
		}
	return C ;
	}
}

vector<vector<double> > powmat(vector<vector<double> > Q, int n) {
	if(Q.size()!=Q[0].size()) {
		cout << "Non-square matrix !" << endl ;
		return vector<vector<double> >(0) ;
	}
	else if (n==0) {
		return id(Q.size()) ;
	}
	else {
		vector<vector<double> > res=Q ;
		for(int i(1);i<n;i++) {
			res=matmul(res,Q) ;
		}
		return res ;
	}	
}

vector<vector<double> > operator*(vector<vector<double> > A, vector<vector<double> > B) {

	return matmul(A,B) ;
}

vector<vector<double> > P(vector<vector<double> > a) {
	vector<vector<double> > trans(a[0].size(), vector<double>(a[0].size())) ;
	// a is M x N matrix, where the a_ij entry is the payoff for player i in network j.
	// trans is a NxN matrix, where trans_ij is the probability to jump from network k to network l.
	for(size_t k(0);k<trans.size();k++) {
		for(size_t l(0);l<trans.size();l++) {
				if(adj[k][l]!=0) {
					size_t n1=neigh[k][l][0] ;
					size_t n2=neigh[k][l][1] ;
					if(adj[k][l]==1 and ((a[n1][l]>=a[n1][k] and a[n2][l]>a[n2][k]) or (a[n1][l]>a[n1][k] and a[n2][l]>=a[n2][k]) ) ) {
						trans[k][l]+=1./3. ;
					}
					else if (adj[k][l]==-1 and (a[n1][l]>a[n1][k] or a[n2][l]>a[n2][k])) {
						trans[k][l]+=1./3. ;
					}
					else {
						trans[k][k]+=1./3. ;
					}
				}
		}
	}
	//cout << "These are elements in a : " << a[0][0] << " " << a[1][1] << endl ;
	//cout << "This is the first element " << b[0][0] << endl ;
	return trans ;
}

vector<vector<double> > infsum(vector<vector<double> > A, int niter) {
	vector<vector<double> > res(id(A.size())) ;
	vector<vector<double> > temp(id(A.size())) ;
	for(int i(1);i<=niter;++i) {
		temp=matmul(temp,A) ;
		res = res + temp	;
	} 
	return res ;
}

vector<double> resoleqn(vector<vector<double> > const &P, double delta, vector<double> const &initpayoff) {
	int ninter=100 ;
	size_t sizeinit(initpayoff.size()) ;
	vector<vector<double> > initpayofftemp(sizeinit,vector<double>(1)) ;
	for(size_t i(0);i<sizeinit;++i) {
		initpayofftemp[i][0]=initpayoff[i] ;
	}
	vector<vector<double> > temp(matmul(infsum(delta*P,100),initpayofftemp)) ;
	
	vector<double> res(sizeinit) ;
	for(size_t j(0);j<sizeinit;++j) {
		res[j]=temp[j][0] ;
	}
	
	return res ;
}

vector<vector<double> > expectedval(double del, vector<vector<double> > a, int niter) {
	vector<vector<double> > res(a) ;	
	for(int i(0);i<niter;i++) {
		//res=res+a*(powmat(del*P(a),i)+(-1)*id(a[0].size())) ;
		res=res+a*(powmat(del*P(a),i)) ;
	}
	return res ;
}

//probaindiv -- First level : players (3), second level : graphs (8), third level : neighbours (3)
vector<vector<double> > obtainP(vector<vector<vector<double> > > const & probaindiv) {
	vector<vector<double> > res(vector<vector<double > >(8,vector<double>(8))) ;
	for(size_t k(0); k<neigh.size();k++) {
		for(size_t l(0); l<neigh.size();l++) {
		if(k!=l) {
			if(adj[k][l]==0) {
				res[k][l]=0 ;
			}
			
			else if(adj[k][l]==1) {
				
				res[k][l]=2*probaindiv[neigh[k][l][0]][k][neigh[k][l][1]]*probaindiv[neigh[k][l][1]][k][neigh[k][l][0]]/NPLAYERS ;
			}
			
			else if(adj[k][l]==-1){
				res[k][l]=(probaindiv[neigh[k][l][0]][k][neigh[k][l][1]]+probaindiv[neigh[k][l][1]][k][neigh[k][l][0]])/NPLAYERS ;
				}
			}	
		}
	}
	
	for(size_t k(0); k<neigh.size();k++) {
		double temp(0) ;
		for(size_t l(0); l<neigh.size();l++) {
			temp += res[k][l] ;
		}
		res[k][k]=1-temp ;
	}
	
	return res ;
}

//initpayoff : first level : players(3), second level : networks(8) 
vector<vector<double> > estimpayoff(vector<double> const &delta, vector<vector<double> > const &initpayoff,
									vector<vector<double> > const &Prob) {
	size_t nplay(delta.size()) ;
	vector<vector<double> > U ;
	for(size_t i(0);i<nplay;++i) {
		U.push_back(resoleqn(Prob,delta[i],initpayoff[i])) ;
	}
	
	return U ;
}

// compute del(U_i(g, a))/del(a^{ig}_j)
double calc_partial_derivative(vector<double> const &delta, vector<vector<double> > const &initpayoff, 
							   vector<vector<vector<double> > > const & probaindiv, size_t g, size_t i, size_t j, int niter) {
	double res(0);
	bool is_in_network(is_network(g, i, j)) ;
	vector<vector<double> > P = obtainP(probaindiv) ;
	for(int n(0); n<niter ; n++) {
		double res_n(0);
		for(int k(0); k<n; k++) {
			vector<vector<double> > Ppow = powmat(P, n-k-1) ;
			res_n += (scalar_prod(Ppow[neigh_network(g, i, j)], initpayoff[i]) - scalar_prod(Ppow[g], initpayoff[i]))*powmat(P, k)[g][g] ;
		}
		res += res_n * pow(delta[i], n);
	}
	
	if(is_in_network) {
		res*= 1.0/NPLAYERS ; 
	}
	else {
		res*= 2.0*probaindiv[j][g][i]/NPLAYERS ; 
	}
	
	return res;						 							   	
}

//step of gradient descent
void optimizer_step(vector<double> const &delta, vector<vector<double> > const &initpayoff,
					vector<vector<vector<double> > > &probaindiv, int niter, double lr) {
  int count(0) ;
  vector<double> gradient_size(0) ;
  double gradient_cumul(0) ; 
  while(count < 10000) {
    //define i,j,g
	size_t i = rand() % NPLAYERS ;
	size_t j1 = (i+1) % NPLAYERS ;
	size_t j2 = (i+2) % NPLAYERS ;
	size_t g = rand() % 8 ;
	vector<double> grad(2);
	grad[0] = calc_partial_derivative(delta, initpayoff, probaindiv, g, i, j1, niter) ;
	grad[1] = calc_partial_derivative(delta, initpayoff, probaindiv, g, i, j2, niter) ;
	//we have to prevent the parameters going outside the triangle region x+y <= 1, x,y>=0
	double pos1 = probaindiv[i][g][j1] ;
	double pos2 = probaindiv[i][g][j2] ;
	vector<double> update = ((min(lr, min(abs(pos1), min(abs(pos2), abs(1-pos1-pos2)/sqrt(2)))))/(pow(10, -8) + norm(grad))) * grad ;   
	probaindiv[i][g][j1] += update[0] ;
	probaindiv[i][g][j2] += update[1] ;
	probaindiv[i][g][i] = 1 - probaindiv[i][g][j1] - probaindiv[i][g][j2] ;
	gradient_cumul += norm(update) ;
	count++ ;
	if(count%100 == 0) {
	    gradient_size.push_back(gradient_cumul) ;
	    gradient_cumul = 0 ;
	  }
  }
  cout << "size of the gradients : " << gradient_size << endl ;

}

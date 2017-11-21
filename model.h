#ifndef MODEL_H
#define MODEL_H

std::vector<size_t> getneigh(size_t i, size_t g) ;

size_t getplayer(size_t i, size_t g, size_t h) ;

size_t neigh_network(size_t g, size_t i, size_t j) ;

// whether link (i,j) is in network g
bool is_network(size_t g, size_t i, size_t j) ;

std::vector<std::vector<double> > id(size_t n) ;

std::ostream& operator<<(std::ostream& os, std::vector<double> const& v) ;

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<double> > const& v) ;

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<std::vector<double> > > const& v) ;

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<size_t> > const& v) ;

std::vector<std::vector<double> > operator+(std::vector<std::vector<double> > A, std::vector<std::vector<double> > B) ;

std::vector<double> operator*(double const& r, std::vector<double> a) ;

std::vector<std::vector<double> > operator*(double const& r, std::vector<std::vector<double> > A) ;

double scalar_prod(std::vector<double> a, std::vector<double> b) ;

double norm(std::vector<double> a) ;

std::vector<std::vector<double> > matmul(std::vector<std::vector<double> > A, std::vector<std::vector<double> > B) ;

std::vector<std::vector<double> > powmat(std::vector<std::vector<double> > Q, int n) ;

std::vector<std::vector<double> > operator*(std::vector<std::vector<double> > A, std::vector<std::vector<double> > B) ;

//this function P is really weird, check it off, and where it is applied! in expectedval
std::vector<std::vector<double> > P(std::vector<std::vector<double> > a) ;

std::vector<std::vector<double> > infsum(std::vector<std::vector<double> > A, int niter) ;

std::vector<double> resoleqn(std::vector<std::vector<double> > const &P, double delta, std::vector<double> const &initpayoff) ;

std::vector<std::vector<double> > expectedval(double del, std::vector<std::vector<double> > a, int niter) ;

std::vector<std::vector<double> > obtainP(std::vector<std::vector<std::vector<double> > > const & probaindiv) ;

std::vector<std::vector<double> > estimpayoff(std::vector<double> const &delta, std::vector<std::vector<double> > const &initpayoff,
											  std::vector<std::vector<double> > const &Prob) ;

//generates a positive vector of L1 norm = 1 in R^n, n>=2.
std::vector<double> initproba(int n) ;

//randomly initialize the vector of individual probabilities
void initprobaindiv(std::vector<std::vector<std::vector<double> > > &probaindiv) ;

//compute the derivative of U_i(g, a) with respect to a^{ig}_j
double calc_partial_derivative(std::vector<double> const &delta, std::vector<std::vector<double> > const &initpayoff, 
							   std::vector<std::vector<std::vector<double> > > const & probaindiv, size_t g, size_t i, size_t j, int niter) ;

void optimizer_step(std::vector<double> const &delta, std::vector<std::vector<double> > const &initpayoff,
					std::vector<std::vector<std::vector<double> > > &probaindiv, int niter, double lr) ;

#endif

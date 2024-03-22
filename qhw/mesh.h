#include "matrix.h"

Dense area(const Dense& V, const DenseInt& F);


Dense volume(const Dense& V, const DenseInt& F);

struct Grad {
public:
	Dense g0;
	Dense g1;
	Dense g2;
	Dense g3;
};

Grad compute_grads_pre(const Dense& V, const DenseInt& F);

void compute_grads(const Dense& V, const DenseInt& F, const Grad& grad, const Dense& W, Dense& GW);

void sparse_grads(const Dense& V, const DenseInt& F,
	const DenseInt& known,
	Sparse& Gx, Sparse& Gy,
	Sparse& Gz,
	Sparse& Gxk, Sparse& Gxu, Sparse& Gyk, Sparse& Gyu,
	Sparse& Gzk, Sparse& Gzu);

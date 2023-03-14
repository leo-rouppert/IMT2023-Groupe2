#include "constantblackscholesprocess.hpp"

namespace QuantLib {
	ConstantBlackScholesProcess::ConstantBlackScholesProcess(double SPOT_VAL, double RF, double DIV_YIELD, double VOL)
	{
		spot_val = SPOT_VAL;
		rf = RF;
		div_yield = DIV_YIELD;
		vol = VOL;
	}

	ConstantBlackScholesProcess::~ConstantBlackScholesProcess()
	{
	}

	double ConstantBlackScholesProcess::getSpot_val() const
	{
		return spot_val;
	}

	double ConstantBlackScholesProcess::getRf() const
	{
		return rf;
	}

	double ConstantBlackScholesProcess::getDiv_yield() const
	{
		return div_yield;
	}

	double ConstantBlackScholesProcess::getVol() const
	{
		return vol;
	}

	Real ConstantBlackScholesProcess::x0() const
	{
		return this->getSpot_val();
	}

	Real ConstantBlackScholesProcess::drift(Time t, Real x) const
	{
		return this->getRf() - this->getDiv_yield() - 0.5 * this->getVol() * this->getVol();
	}

	Real ConstantBlackScholesProcess::diffusion(Time t, Real x) const
	{
		return this->getVol();
	}
}
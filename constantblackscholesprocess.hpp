#ifndef CONSTANTBLACKSCHOLESPROCESS
#define CONSTANTBLACKSCHOLESPROCESS
#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {

    private:
        double spot_val;
        double rf;
        double div_yield;
        double vol;

    public:
        ConstantBlackScholesProcess(double spot_val, double rf, double div_yield, double vol);
        ~ConstantBlackScholesProcess();

        double getSpot_val() const;
        double getRf() const;
        double getDiv_yield() const;
        double getVol() const;

        Real x0() const ;
        Real drift(Time t, Real x) const;
        Real diffusion(Time t, Real x) const;
        Real apply(Real x0, Real dx) const;
    };

}
#endif

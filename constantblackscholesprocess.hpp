#ifndef CONSTANTBLACKSCHOLESPROCESS
#define CONSTANTBLACKSCHOLESPROCESS
#include <ql/stochasticprocess.hpp>
#include <ql/processes/blackscholesprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {

    private:
        double spot_val;
        double rf;
        double div_yield;
        double vol;

    public:
        ConstantBlackScholesProcess(double spot_val, double rf, double div_yield, double vol);
        ConstantBlackScholesProcess(GeneralizedBlackScholesProcess process, Time T, double strike); //Constructor from a general BS process (avoid copy paste of code)
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

#include <matplot/matplot.h>
#include <set>

int main() {
    using namespace matplot;

    std::set<std::vector<double>> Y = {
        {16, 5, 9, 4}, {2, 11, 7, 14}, {3, 10, 6, 15}, {13, 8, 12, 1}};
    plot(Y);

    //show();  // does not work on docker systems without DISPLAY
    // you may need to set GNUTERM=png or something without a display
    save("img/mplexample_fig.png");
    save("img/mplexample_fig.pdf");
    save("img/mplexample_fig.tex");
    return 0;
}

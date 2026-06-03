// График функции y = 2 * sin(x) * e^(4/5) на интервале [-50, 50]
// Вывод в консоль + сохранение в файл data.csv для построения в Excel/gnuplot

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

int main() {
    const double E_COEFF = std::exp(4.0 / 5.0);  // e^(4/5) ≈ 2.2255
    const double START = -50.0;
    const double END   =  50.0;
    const double STEP  =  0.5;

    std::ofstream csv("data.csv");
    csv << "x,y\n";

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "y = 2 * sin(x) * e^(4/5),  e^(4/5) = " << E_COEFF << "\n\n";
    std::cout << std::setw(10) << "x" << std::setw(15) << "y" << "\n";
    std::cout << std::string(25, '-') << "\n";

    for (double x = START; x <= END; x += STEP) {
        double y = 2.0 * std::sin(x) * E_COEFF;
        std::cout << std::setw(10) << x << std::setw(15) << y << "\n";
        csv << x << "," << y << "\n";
    }

    std::cout << "\nДанные сохранены в data.csv\n";
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

class PhuongTrinh {
protected:
    double a, b, c, d;

public:
    PhuongTrinh() {
        a = 1;
        b = 0;
        c = 0;
        d = 0;
    }

    PhuongTrinh(double a, double b, double c, double d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    // Ham ao thuan tuy
    virtual void solve() = 0;

    // Getter
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }

    // Setter
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }
    void setD(double d) { this->d = d; }

    virtual ~PhuongTrinh() = default;
};

// ==================== PHUONG TRINH BAC 1 ====================
class PhuongTrinhBac1 : public PhuongTrinh {
public:
    PhuongTrinhBac1() : PhuongTrinh(1, 0, 0, 0) {}

    PhuongTrinhBac1(double a, double b) : PhuongTrinh(a, b, 0, 0) {}

    void solve() override {
        if (a == 0) {
            if (b == 0)
                cout << "Phuong trinh vo so nghiem\n";
            else
                cout << "Phuong trinh vo nghiem\n";
        } else {
            cout << "x = " << -b / a << endl;
        }
    }
};

// ==================== PHUONG TRINH BAC 2 ====================
class PhuongTrinhBac2 : public PhuongTrinh {
public:
    PhuongTrinhBac2() : PhuongTrinh(1, 0, 0, 0) {}

    PhuongTrinhBac2(double a, double b, double c) : PhuongTrinh(a, b, c, 0) {}

    void solve() override {
        if (a == 0) {
            PhuongTrinhBac1 pt(b, c);
            pt.solve();
            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem thuc\n";
        } else if (delta == 0) {
            cout << "x = " << -b / (2 * a) << endl;
        } else {
            cout << "x1 = "
                 << (-b + sqrt(delta)) / (2 * a) << endl;

            cout << "x2 = "
                 << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
};

// ==================== PHUONG TRINH BAC 3 ====================
class PhuongTrinhBac3 : public PhuongTrinh {
public:
    PhuongTrinhBac3() : PhuongTrinh(1, 0, 0, 0) {}

    PhuongTrinhBac3(double a, double b, double c, double d) : PhuongTrinh(a, b, c, d) {}

    void solve() override {
        if (a == 0) {
            PhuongTrinhBac2 pt(b, c, d);
            pt.solve();
            return;
        }

        double A = b / a;
        double B = c / a;
        double C = d / a;

        double p = B - A * A / 3.0;

        double q = 2 * A * A * A / 27.0
                   - A * B / 3.0 + C;

        double delta = q * q / 4.0
                       + p * p * p / 27.0;

        if (delta > 1e-12) {
            double u = cbrt(-q / 2.0 + sqrt(delta));
            double v = cbrt(-q / 2.0 - sqrt(delta));

            cout << "x = " << u + v - A / 3.0 << endl;

        } else if (delta >= -1e-12) {
            double u = cbrt(-q / 2.0);

            cout << "x1 = " << 2 * u - A / 3.0 << endl;
            cout << "x2 = " << -u - A / 3.0 << endl;

        } else {
            const double PI = acos(-1.0);

            double r = 2 * sqrt(-p / 3.0);

            double theta = acos(
                (3 * q / (2 * p)) * sqrt(-3.0 / p)
            ) / 3.0;

            for (int k = 0; k < 3; k++) {
                double x = r * cos(theta - 2 * PI * k / 3.0)
                           - A / 3.0;

                cout << "x" << k + 1 << " = " << x << endl;
            }
        }
    }
};

// ==================== HAM MAIN ====================
int main() {
    PhuongTrinhBac1 pt1(2, -4);
    PhuongTrinhBac2 pt2(1, -3, 2);
    PhuongTrinhBac3 pt3(1, -6, 11, -6);

    // Mang con tro lop cha
    PhuongTrinh* ds[] = {&pt1, &pt2, &pt3};

    int n = sizeof(ds) / sizeof(ds[0]);

    for (int i = 0; i < n; ++i) {
        cout << "\nPhuong trinh thu " << i + 1 << ":\n";
        ds[i]->solve();
    }

    return 0;
}

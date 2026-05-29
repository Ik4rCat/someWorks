#pragma once

#include <string>
#include <vector>

using namespace std;

struct LineItem {
    string name;
    double unitPrice;
    int quantity;
};

// Strategy: разные правила расчёта итоговой суммы заказа
class IPricingStrategy {
public:
    virtual ~IPricingStrategy() = default;
    virtual double computeTotal(const vector<LineItem>& items) const = 0;
};

class RegularPricingStrategy : public IPricingStrategy {
public:
    double computeTotal(const vector<LineItem>& items) const override {
        double total = 0;
        for (const auto& i : items)
            total += i.unitPrice * i.quantity;
        return total;
    }
};

class StudentDiscountStrategy : public IPricingStrategy {
    double discountFraction;

public:
    explicit StudentDiscountStrategy(double fraction = 0.15) : discountFraction(fraction) {}

    double computeTotal(const vector<LineItem>& items) const override {
        double total = 0;
        for (const auto& i : items)
            total += i.unitPrice * i.quantity;
        return total * (1.0 - discountFraction);
    }
};

class ShoppingCart {
    vector<LineItem> items;
    IPricingStrategy* strategy;

public:
    explicit ShoppingCart(IPricingStrategy* s) : strategy(s) {}

    void setStrategy(IPricingStrategy* s) { strategy = s; }

    void addItem(const LineItem& item) { items.push_back(item); }

    double checkoutTotal() const { return strategy->computeTotal(items); }

    const vector<LineItem>& getItems() const { return items; }
};

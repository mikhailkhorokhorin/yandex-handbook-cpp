class B : public A {
   public:
    B() : A(42) {
    }
    void foo() const override {
    }
};

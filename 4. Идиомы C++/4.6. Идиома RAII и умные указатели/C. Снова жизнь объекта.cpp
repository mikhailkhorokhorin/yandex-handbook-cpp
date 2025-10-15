class B : public A {
   private:
    A a_;

   public:
    B() : A(42), a_(17) {
    }
};

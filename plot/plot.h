class Plot
{
    unsigned long * fn_heights;
    int steps;
    public:
        Plot(int size_of_steps);
        void draw();
        void refresh_plot(float* fn_results, int size);
};

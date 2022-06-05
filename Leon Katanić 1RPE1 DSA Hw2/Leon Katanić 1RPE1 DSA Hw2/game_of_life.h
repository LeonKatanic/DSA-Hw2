class GoL
{
private:
	static const unsigned int Colum = 40;
	static const unsigned int Row = 20;
	char current[Row][Colum];
	char next[Row][Colum];
	int checkNeighbour(int row, int column);
	int rndNum(int max, int min);
	void rndDisplay();
	void display();
	void nextStep();
	void copy();
public:
	void start();

};
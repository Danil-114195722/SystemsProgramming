using namespace std;

struct Product {
	string title;
	int cash;
	int stamina;
};

void GetRandomProducts(Product* shopProducts, int count);
void UpdateRandomProducts(Product* shopProducts, int boughtProductIdx, int count);

bool BuyProduct(Product product);

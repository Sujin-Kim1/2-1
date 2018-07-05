class NumberGame
{
  public:
    enum Case { kStrike, kBall, kNone };

  public:
    NumberGame()
    {
        for (unsigned int i = 0; i < MAX_NUMBER; ++i)
            candidate[i] = true;
    }

  public:
    void query(unsigned int n, unsigned int s.unsigned int b);

  private:
    void compute(const int i, const int n, int& comp_s, int& comp_b);
    Case check(const int key, const int query_digit, const int Nth);
    int convert_to_digit(int key, int key_digit);

  private:
    bool candidate[MAX_NUMBER];
    const unsigned int MAX_NUMBER = 10000;
};

void NumberGame::query(unsigned int n, unsigned int s, unsigned int b)
{
    int comp_s, comp_b;

    for (unsigned int i = 0; i < MAX_NUMBER; ++i)
    {
        compute(i, n, comp_s, comp_b);

        if (s != comp_s || b != comp_b)
            candidate[i] = false;    
    }
}

// 하나의 질문과 대답에 대하여, 집합 s에 속하는 모든 숫자 s를 질문에서 제시된
// 숫자와 비교하여 같은 자리에 같은 숫자가 있는 경우의 수인 스트라이크와 다른
// 자리에 같은 숫자가 있는 경우의 수인 볼을 계산한다.
void compute(const int key, const int query, int& comp_s, int& comp_b)
{
    unsigned int query_digit[4];

    convert_to_digit(query, query_digit);

    comp_s = 0;
    comp_b = 0;

    for (unsigned int i = 0; i < 4; ++i)
    {
        check(key, query_digit[i], i);
        
        // for (unsigned int j = 0; j < 4; ++j)
        // {
        //     if (key_digit[j] == query_digit[i])
        //     {
        //         (i == j) ? ++comp_s : ++comp_b;
        //     }
        // }
    }
}

Case check(const int key, const int query_digit, const int Nth)
{
    unsigned int key_digit[4];
    convert_to_digit(key, key_digit);
}

int main()
{

}
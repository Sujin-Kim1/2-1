class vec2f
{
  public:
    float operator()(unsigned int idx) const;
    float &operator()(unsigned int idx);

  private:
    float x, y;
}

/* template이면 이렇게 나눠서 하면 X
T를 결정하는 게 vec2.cpp파일에 있기때문에 실존하는 코드가 없음 
h파일만 include하기 때문 -> h파일에 Template 다 때려 박아야 함 
=> 내가 짠 소스코드 logic을 숨길 수가 없음 */
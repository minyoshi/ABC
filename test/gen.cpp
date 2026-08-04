#include "template.cpp"
// テストケースを作成する（入力例のみ）
void _main() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> num(1, 100);
}

int main() {
    cin.tie(0); 
    ios::sync_with_stdio(false);
    _main();
    return 0;
}
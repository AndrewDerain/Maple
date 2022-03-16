
#define attribute_
#define attribute_api

#define attribute(...) attribute_##__VA_ARGS__ 







// Attribute(API INLINE)
//Decorate(fantasia, api, inline, constexpr)
void func(){

}   

int main(){
    return 0;
}

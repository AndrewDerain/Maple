#pragma once
#include "../Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Algorithm
{

    class Heapsort
    {
    public:
        template<typename _Ty, Size _Capacity>
        inline constexpr
        static void Sort(_Ty (&arr)[_Capacity], int count) {

            for(int i = count / 2; i >= 0; --i) {
                PercDown(arr, i, count);
            }

            for(int i = count - 1; i > 0; --i) {
                //Swap(arr[0], arr[i]);

                _Ty tmp = arr[0];
                arr[0] = arr[i];
                arr[i] = arr[0];

                PercDown(arr, 0, i);
            }
        }


    protected:
        template<typename _Ty, Size _Capacity>
        inline constexpr
        static void PercDown(_Ty (&arr)[_Capacity], int i, int count) {

            int Child;
            _Ty Item;

            for(Item = arr[i]; LeftChild(i) < count; i = Child) {

                Child = LeftChild(i);

                if(Child != count - 1 && arr[Child + 1] > arr[Child]) {
                    ++Child;
                }

                if(Item < arr[Child]) {
                    arr[i] = arr[Child];
                }
                else break;
            }

            arr[i] = Item;
        }

        inline constexpr
        static int LeftChild(int i) {
            return 2 * i + 1;
        }
    };


} // namespace _Maple::Algorithm
#pragma pack(pop)
#pragma warning(pop)

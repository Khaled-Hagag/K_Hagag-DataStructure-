#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
    int _Size = 0;
    T* _TempArray;


public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }
    //هستخدمه ف الاخر
    // يبقي حد يقول مش فاهمه
    ~clsDynamicArray()
    {
        delete[]  OriginalArray;
    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()

    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }


    void Resize(int NewSize)
    {
        if (NewSize <= 0)
        {
            NewSize = 0;
        };


        _TempArray = new T[NewSize];

        if (NewSize < _Size)
            _Size = NewSize;

        for (int i = 0; i < NewSize; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;//if say (Size = NewSize); Fucken Error لانها ميتين لوكال فاريابول بلاش غباء
        delete[] OriginalArray;

        OriginalArray = _TempArray;

    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

    void Reverse()
    {
        int Counter = 0;
        T* _TempArray = new T[_Size];
        for (int i = _Size - 1; i >= 0; i--)
        {
            _TempArray[i] = OriginalArray[Counter];
            Counter++;
        }
        delete[] OriginalArray;

        OriginalArray = _TempArray;

    }

    void Clear()
    {
        delete[] OriginalArray;
        _Size = 0;
    }

   

    bool DeleteItemAt(int index)
    {

        if (index >= _Size || index < 0)
        {
            return false;
        }

        _Size--;

        _TempArray = new T[_Size];

        //copy ele before index 
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        //copy ele after index
        for (int i = index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }
        //اللي بيسال مين ele دي هبقي اقولك
        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

        //اوعي تكون بتفكر انك تحذف ال اراي اللي فيها الاندكس بس يعني مثلا
        //delete OriginalArray[index]
        // احمس انت كدا مش بني ادم انا فكرت فكدا بعديها جلدت نفسي ميت جلده 
        //لانك لو عملت كدا يبقي بتحذف البوينتر كله بالعناصر كلها 
        //لان دا بوينتر مش سايبه هي احنا هنا الموضوع حساس يابيه مش سايبه هي
        //لو انت مفكرتش اصلا وقاعد بتحفظ وانت مش فاهم حاجه زي عبراضي المجتهد يبقي انت كدا ميا ميا 
        //لو انت محنك زي الدالي  يبقي طرد
        //منور يا غالي اوعي تكون فكرت زيهم 
    }

    bool DeleteFirstItemAt()
    {
        return DeleteItemAt(0);
    }


    bool DeleteLastItemAt()
    {
        return DeleteItemAt(_Size - 1);
    }

    
    int Find(T Value) {
        for (int i = 0; i < _Size; i++) {
            if (OriginalArray[i] == Value) {
                return i;
            }
        }
        return -1;
    }


    bool DeleteItem(T Value) 
    {
        int index = Find(Value);

        if (index == -1)
        {
            return false;
        }

        DeleteItemAt(index);
        return true;

    }

    void Change(T Index, T Value)
    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            if (Index == i)
            {
                OriginalArray[i] = Value;
            }
        }
    }

    bool InsertAt(T index, T value) {

        if (index > _Size || index < 0)
        {
            return false;
        }

        _Size++;

        _TempArray = new T[_Size];

        //copy ele before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[index] = value;

        //copy ele after index
        for (int i = index; i < _Size - 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
        //اوعي تكون فكرت ف اللي بفكر فيه
    }

    void InsertAtBeginnging(T Value) {

        InsertAt(0, Value);
    }

    void InsertAtEnd(T Value) {

        InsertAt(_Size, Value);
    }

    bool InserBefore(T Index, T Value) {
        
        return Index < 1 ? InsertAt(0, Value) : InsertAt(Index - 1, Value);
    }

    bool InserAfter(T Index, T Value) {

        return Index >= _Size ? InsertAt(_Size - 1, Value) : InsertAt(Index + 1, Value);
    }

    //حل البقر الجاموس والحلاليف ولاد ال  ..
    // 
//    bool InsertAtBeginning( T Value)
//    {
//
//        
//        _Size++;
//
//        _TempArray = new T[_Size];
//
//
//        
//
//        _TempArray[0] = Value;
//
//        //copy all after index
//        for (int i = 0; i < _Size; i++)
//        {
//            _TempArray[i + 1] = OriginalArray[i];
//        }
//
//        delete[] OriginalArray;
//        OriginalArray = _TempArray;
//        return true;
//
//    }
//    
//    bool InsertBefore(T Index, T Value)
//    {
//
//        if (Index >= _Size || Index < 0)
//        {
//            return false;
//        }
//
//        _Size++;
//
//        _TempArray = new T[_Size];
//
//
//        //copy all before index
//        for (int i = 0; i < Index; i++)
//        {
//            _TempArray[i] = OriginalArray[i];
//        }
//
//        _TempArray[Index] = Value;
//
//        //copy all after index
//        for (int i = Index ; i < _Size; i++)
//        {
//            _TempArray[i + 1] = OriginalArray[i];
//        }
//
//        delete[] OriginalArray;
//        OriginalArray = _TempArray;
//        return true;
//
//    }
//
//
//     bool InsertAfter(T Index, T Value)
//    {
//
//        if (Index >= _Size || Index < 0)
//        {
//            return false;
//        }
//
//        _Size++;
//
//        _TempArray = new T[_Size];
//
//
//        //copy all before index
//        for (int i = 0; i <= Index; i++)
//        {
//            _TempArray[i] = OriginalArray[i];
//        }
//
//        _TempArray[Index + 1] = Value;
//
//        //copy all after index
//        for (int i = Index+1 ; i < _Size; i++)
//        {
//            _TempArray[i + 1] = OriginalArray[i];
//        }
//
//        delete[] OriginalArray;
//        OriginalArray = _TempArray;
//        return true;
//
//    }
//
//
//
//     bool InsertAtTheEnd(T Value)
//     {
//
//
//         _Size++;
//
//         _TempArray = new T[_Size];
//
//
//
//
//         
//         //copy all after index
//         for (int i = 0; i < _Size; i++)
//         {
//             _TempArray[i] = OriginalArray[i];
//         }
//         _TempArray[_Size+1] = Value;
//
//         delete[] OriginalArray;
//         OriginalArray = _TempArray;
//         return true;
//
//     }
};


using namespace std;
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

float some_fn(float arg1, float arg2){
 return arg1+arg2;
}

void test(//long (&sizes)[1],
         vector<long> &adjMatrix_row_ptr,
         const vector<long> &adjMatrix_col_ind)
{
  for (int i = 0; i< adjMatrix_row_ptr.size(); i++)
  {
    adjMatrix_row_ptr[i]=5;     
    cout << "m. single parents = " << adjMatrix_row_ptr[i] << endl;
  }
}

PYBIND11_MODULE(module_name, module_handle) {
  module_handle.doc() = "I'm a docstring hehe";
  module_handle.def("some_fn_python_name", &some_fn);
  module_handle.def("test",
  [](vector<long> adjMatrix_row_ptr,const vector<long> adjMatrix_col_ind)
      {
          test(adjMatrix_row_ptr,adjMatrix_col_ind);
          return std::make_tuple(adjMatrix_row_ptr);
      });


//  module_handle.def("some_fn_python_name", &test);

}

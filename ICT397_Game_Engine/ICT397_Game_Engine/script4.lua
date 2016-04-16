--luatest4.lua
--example of exposing C++ function

multiply=cpp_Multiply(5,7);

add=cpp_Add(3,2);

print("Multiplication = "..multiply);
print("Adding = "..add);

--print(cpp_Multiply(5,6));
--another way of writing it


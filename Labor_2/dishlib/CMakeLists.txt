add_library(
        dishlib
        AbstractDish.cpp
        VegetableSoup.cpp
        PizzaMargherita.cpp
        DishFactory.cpp
)

target_include_directories(
        dishlib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cvjit-pretarget.cmake)


add_library( 
	${PROJECT_NAME} 
	MODULE
	${PROJECT_NAME}.cpp
	max.${PROJECT_NAME}.cpp
	OpticalFlow.cpp
)


include(${CMAKE_CURRENT_SOURCE_DIR}/../cvjit-posttarget.cmake)

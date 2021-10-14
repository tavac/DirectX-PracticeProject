add_executable(LF-GFX_DEBUG WinMain.cpp)
set_target_properties(LF-GFX_DEBUG PROPERTIES WIN32_EXECUTABLE $<CONFIG:Debug>)

# add_executable(LF-GFX_RELEASE WinMain.cpp)
# set_target_properties(LF-GFX_RELEASE PROPERTIES WIN32_EXECUTABLE $<CONFIG:Release>)
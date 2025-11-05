#include "APeregrinatorsTale.h"

#include <functional>	// for functionn
#include <memory>		// for make_shared & shared_ptr
#include <utility>		// for forward

#include <ftxui/util/warn_windows_macro.hpp>
#include "ftxui/component/component_base.hpp" // for Component & Components
#include "ftxui/component/component_options.hpp"  // for ButtonOption, CheckboxOption & MenuOption
#include "ftxui/dom/elements.hpp" // for Element
#include "ftxui/util/ref.hpp"  // for ConstRef, Ref, ConstStringRef, ConstStringListRef & StringRef

#include <iostream>
#include <algorithm>

#define NOMINMAX
#define WINDOWS32_LEAN_AND_MEAN
#include <Windows.h>

using namespace std;

int main()
{

	// display_main_menu()

	









	auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
	Render(screen, document);
	screen.Print();

	return 0;

}

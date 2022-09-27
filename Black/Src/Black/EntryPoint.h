#pragma once
#ifdef  BLACK_PLATFORM_WINDOWS


	extern Black::Application* Black::CreateApplication();

	int main(int argc, char** argv)
	{
		Black::Log::Init();
		BLACK_LOG_INFO("Black Initialized");
		BLACK_WARN("Hello Black Engine!");

		auto app = Black:: CreateApplication();
		app->Run();
		delete app;
		return 0;
	}

#endif //  BLACK_PLATFORM_WINDOWS

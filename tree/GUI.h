#pragma once

#if __has_include(<graphics.h>)

#include <graphics.h>

namespace UI {
	/**** 按钮 ****/
	class Button {
	private:
		int width = 0, height = 0;

	public:
		/**** 控件左上角的x坐标 ****/
		int x = 0,

			/**** 控件左上角的y坐标 ****/
			y = 0;

		/**** 控件所显示的文本 ****/
		LPTSTR text = new wchar_t[1024];

		/**** 控件显示的文本高度 ****/
		int size = 16;

		/**** 控件是否可见，可见为true，否则为false ****/
		bool visible = false;

		/**** 构造函数，初始化控件左上角的坐标、宽度、高度、显示的文本与文本的高度（默认为16） ****/
		Button(int x, int y, int width, int height, LPCTSTR text, int size = 16) {
			this->x = x;
			this->y = y;
			this->width = width;
			this->height = height;
			lstrcpy(this->text, text);
			this->size = size;
			return;
		}

		/**** 显示控件,成功返回true，出现异常返回false ****/
		bool show() {
			if (visible) {
				//当前控件可见
				return false;
			}
			int temp = getbkmode();
			setbkmode(TRANSPARENT);
			LOGFONT* temp1 = new LOGFONT();
			LOGFONT* temp2 = new LOGFONT();
			gettextstyle(temp1);
			gettextstyle(temp2);
			temp2->lfHeight = size;
			settextstyle(temp2);
			if (width - textwidth(text) <= 0 || height - textheight(text) <= 0) {
				//文字过大
				settextstyle(temp1);
				return false;
			}
			fillrectangle(x, y, x + width - 1, y + height - 1);
			outtextxy(x + (width - textwidth(text)) / 2, y + (height - textheight(text)) / 2, text);
			settextstyle(temp1);
			setbkmode(temp);
			delete temp1;
			delete temp2;
			visible = true;
			return true;
		}

		/**** 隐藏控件 ****/
		void hide() {
			clearrectangle(x, y, x + width - 1, y + height - 1);
			visible = false;
			return;
		}

		/**** 判断按钮是否被按下，被按下返回true，没有按下或出现异常返回false ****/
		bool click(ExMessage m) {
			if (!visible) {
				//当前控件不可见
				return false;
			}
			return m.message == WM_LBUTTONDOWN && (m.x >= x && m.x <= x + width - 1) && (m.y >= y && m.y <= y + height - 1);
		}

		/**** 刷新插件（显示状态下） ****/
		void reload() {
			visible = false;
			show();
			return;
		}

		~Button()
		{
			text = nullptr;
			delete[] text;
			return;
		}
	};

	/**** 文本（该控件为自动调整大小） ****/
	class Label {
	private:
		int width, height;

	public:
		/**** 控件左上角的x坐标 ****/
		int x = 0,

			/**** 控件左上角的y坐标 ****/
			y = 0;

		/**** 控件所显示的文本 ****/
		LPTSTR text = new wchar_t[1024];

		/**** 控件显示的文本高度 ****/
		int size = 16;

		/**** 控件是否可见，可见为true，否则为false ****/
		bool visible = false;

		/**** 构造函数，初始化控件左上角的坐标、显示的文本与文本的高度（默认为16） ****/
		Label(int x, int y, LPCTSTR text, int size = 16) {
			this->x = x;
			this->y = y;
			lstrcpy(this->text, text);
			this->size = size;
			width = 0;
			height = 0;
			return;
		}

		/**** 显示控件,成功返回true，出现异常返回false ****/
		bool show() {
			if (visible) {
				//当前控件可见
				return false;
			}
			int temp = getbkmode();
			setbkmode(TRANSPARENT);
			LOGFONT* temp1 = new LOGFONT();
			LOGFONT* temp2 = new LOGFONT();
			gettextstyle(temp1);
			gettextstyle(temp2);
			temp2->lfHeight = size;
			settextstyle(temp2);
			outtextxy(x, y, text);
			width = textwidth(text);
			height = textheight(text);
			settextstyle(temp1);
			delete temp1;
			delete temp2;
			setbkmode(temp);
			visible = true;
			return true;
		}

		/**** 隐藏控件 ****/
		void hide() {
			clearrectangle(x, y, x + width - 1, y + height - 1);
			visible = false;
			return;
		}

		/**** 刷新插件（显示状态下） ****/
		void reload() {
			visible = false;
			show();
			return;
		}

		~Label()
		{
			text = nullptr;
			delete[] text;
			return;
		}
	};

	/**** 勾选框（该控件为自动大小） ****/
	class CheckBox {
	private:
		//勾选框=按钮+文本
		Button* button;
		Label* label;

	public:
		/**** 控件左上角的x坐标 ****/
		int x = 0,

			/**** 控件左上角的y坐标 ****/
			y = 0;

		/**** 控件所显示的文本 ****/
		LPTSTR text = new wchar_t[1024];

		/**** 是否已被勾选 ****/
		bool state = false;

		/**** 构造函数，初始化控件左上角的坐标与显示的文本 ****/
		CheckBox(int x, int y, LPCTSTR text) {
			this->x = x;
			this->y = y;
			lstrcpy(this->text, text);
			button = new Button(x, y, 18, 18, L"");
			label = new Label(x + 20, y, text, 18);
			return;
		}

		/**** 显示控件,成功返回true，出现异常返回false ****/
		bool show() {
			if (!button->show() || !label->show()) {
				//当前控件可能可见
				hide();
				return false;
			}
			return true;
		}

		/**** 隐藏控件 ****/
		void hide() {
			button->hide();
			label->hide();
			return;
		}

		/**** 控件是否被勾选，按下则切换效果，出现异常返回false ****/
		bool check(ExMessage m) {
			if (!(button->visible && label->visible)) {
				//当前控件不可见
				return false;
			}
			if (button->click(m)) {
				state = !state;
				state ? lstrcpy(button->text, L"√") : lstrcpy(button->text, L"");
				reload();
			}
			return true;
		}

		/**** 刷新插件（显示状态下） ****/
		void reload() {
			button->reload();
			label->reload();
			return;
		}

		~CheckBox()
		{
			text = nullptr;
			button = nullptr;
			label = nullptr;
			delete[] text;
			delete button;
			delete label;
			return;
		}
	};

	/**** 复选框（最多15项，该控件为自动大小） ****/
	class CheckedListBox {
	private:
		int num = 0;

	public:
		//复选框=多个勾选框
		CheckBox* checkbox[15] = { nullptr };

		/**** 控件左上角的x坐标 ****/
		int x = 0,

			/**** 控件左上角的y坐标 ****/
			y = 0;

		/**** 构造函数，初始化控件左上角的坐标与显示的文本 ****/
		CheckedListBox(int x, int y, int num, LPCTSTR text[]) {
			this->x = x;
			this->y = y;
			if (num > 15) {
				MessageBox(0, L"项数过多！", L"UI.h", MB_OK | MB_ICONSTOP);
				return;
			}
			this->num = num;
			for (int i = 0; i < num; i++) {
				checkbox[i] = new CheckBox(x + 5, y + 5 + i * 20, text[i]);
			}
		}
		CheckedListBox(int num, CheckBox checkbox[]) {
			this->x = checkbox[0].x - 5;
			this->y = checkbox[0].y - 5;
			if (num > 15) {
				MessageBox(0, L"项数过多！", L"UI.h", MB_OK | MB_ICONSTOP);
				return;
			}
			this->num = num;
			for (int i = 0; i < num; i++) {
				this->checkbox[i] = &checkbox[i];
			}
		}

		/**** 显示控件,成功返回true，出现异常返回false ****/
		bool show() {
			int maxlen = 0;
			for (int i = 0; i < num; i++) {
				maxlen = max(maxlen, textwidth(checkbox[i]->text));
				if (!checkbox[i]->show()) {
					for (int j = 0; j < i; j++) {
						checkbox[j]->hide();
						return false;
					}
				}
			}
			rectangle(x, y, x + maxlen + 30, y + num * 20 + 8);
			return true;
		}

		/**** 隐藏控件 ****/
		void hide() {
			for (int i = 0; i < num; i++) checkbox[i]->hide();
			return;
		}

		/**** 控件是否被勾选，按下则切换效果，出现异常返回false ****/
		bool check(ExMessage m) {
			for (int i = 0; i < num; i++) {
				if (!checkbox[i]->check(m))return false;
			}
			return true;
		}

		/**** 刷新插件（显示状态下） ****/
		void relad() {
			for (int i = 0; i < num; i++)checkbox[i]->reload();
			return;
		}

		~CheckedListBox()
		{
			for (int i = 0; i < num; i++) {
				checkbox[i] = nullptr;
				delete checkbox[i];
			}
			return;
		}
	};

	/**** 文本框 ****/
	class TextBox {
	private:
		int width, height = 22;
		Button* button;
		Label* label;

	public:
		/**** 控件左上角的x坐标 ****/
		int x = 0,

			/**** 控件左上角的y坐标 ****/
			y = 0;

		/**** 控件所显示的文本 ****/
		LPTSTR text = new wchar_t[1024];

		/**** 构造函数，初始化控件左上角的坐标与显示的文本 ****/
		TextBox(int x, int y, int width) {
			this->x = x;
			this->y = y;
			this->width = width;
			this->height = height;
			lstrcpy(text, L" ");
			button = new Button(x, y, width, height, L"");
			label = new Label(x + 5, y + 3, L"");
			return;
		}

		/**** 显示控件,成功返回true，出现异常返回false ****/
		bool show() {
			if (!button->show() || !label->show()) {
				hide();
				return false;
			}
			return true;
		}

		/**** 隐藏控件 ****/
		void hide() {
			button->hide();
			label->hide();
			return;
		}

		/**** 刷新插件（显示状态下） ****/
		void reload() {
			button->reload();
			label->reload();
			return;
		}

		/**** 输入文本 ****/
		void in() {
			ExMessage m;
			int count = -1;
			size_t len = 0;
			bool state = false;
			while (true) {
				m.message = 0;
				peekmessage(&m, EM_MOUSE | EM_CHAR);
				if (m.message == WM_LBUTTONDOWN) {
					if (!button->click(m)) {
						state = false;
						goto End;
					}
					state = true;
				}
				else if (m.message == WM_CHAR && state) {
					len = wcslen(label->text);
					switch (m.ch) {
					case '\b':
						if (len > 0) {
							label->text[len - 1] = 0;
							clearrectangle(x + 1 + textwidth(label->text), y + 3, x + width - 2, y + height - 4);
							lstrcpy(text, label->text);
							label->reload();
						}
						break;
					case '\n':
					case '\r':
						state = false;
						goto End;
						break;
					default:
						label->text[len++] = m.ch;
						label->text[len] = 0;
						if (textwidth(label->text) < width - 10) {
							label->text[--len] = 0;
							clearrectangle(x + 5 + textwidth(label->text), y + 3, x + 5 + textwidth(label->text), y + height - 4);
							label->text[len++] = m.ch;
							lstrcpy(text, label->text);
							label->reload();
						}
						else {
							label->text[--len] = 0;
						}
						break;
					}
				}
				count = (count + 1) % 64;
				if (count < 32 && state) line(x + 5 + textwidth(label->text), y + 3, x + 5 + textwidth(label->text), y + height - 4);
				else if (state) clearrectangle(x + 5 + textwidth(label->text), y + 3, x + 5 + textwidth(label->text), y + height - 4);
				Sleep(10);
			}
		End:
			clearrectangle(x + 5 + textwidth(label->text), y + 3, x + 5 + textwidth(label->text), y + height - 4);
			return;
		}

		~TextBox()
		{
			delete button;
			delete label;
			return;
		}
	};
}
#else
#error 宝你没装easyx喵~
#endif
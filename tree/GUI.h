#pragma once

#if __has_include(<graphics.h>)

#include <graphics.h>

namespace UI {
	/**** ��ť ****/
	class Button {
	private:
		int width = 0, height = 0;

	public:
		/**** �ؼ����Ͻǵ�x���� ****/
		int x = 0,

			/**** �ؼ����Ͻǵ�y���� ****/
			y = 0;

		/**** �ؼ�����ʾ���ı� ****/
		LPTSTR text = new wchar_t[1024];

		/**** �ؼ���ʾ���ı��߶� ****/
		int size = 16;

		/**** �ؼ��Ƿ�ɼ����ɼ�Ϊtrue������Ϊfalse ****/
		bool visible = false;

		/**** ���캯������ʼ���ؼ����Ͻǵ����ꡢ��ȡ��߶ȡ���ʾ���ı����ı��ĸ߶ȣ�Ĭ��Ϊ16�� ****/
		Button(int x, int y, int width, int height, LPCTSTR text, int size = 16) {
			this->x = x;
			this->y = y;
			this->width = width;
			this->height = height;
			lstrcpy(this->text, text);
			this->size = size;
			return;
		}

		/**** ��ʾ�ؼ�,�ɹ�����true�������쳣����false ****/
		bool show() {
			if (visible) {
				//��ǰ�ؼ��ɼ�
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
				//���ֹ���
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

		/**** ���ؿؼ� ****/
		void hide() {
			clearrectangle(x, y, x + width - 1, y + height - 1);
			visible = false;
			return;
		}

		/**** �жϰ�ť�Ƿ񱻰��£������·���true��û�а��»�����쳣����false ****/
		bool click(ExMessage m) {
			if (!visible) {
				//��ǰ�ؼ����ɼ�
				return false;
			}
			return m.message == WM_LBUTTONDOWN && (m.x >= x && m.x <= x + width - 1) && (m.y >= y && m.y <= y + height - 1);
		}

		/**** ˢ�²������ʾ״̬�£� ****/
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

	/**** �ı����ÿؼ�Ϊ�Զ�������С�� ****/
	class Label {
	private:
		int width, height;

	public:
		/**** �ؼ����Ͻǵ�x���� ****/
		int x = 0,

			/**** �ؼ����Ͻǵ�y���� ****/
			y = 0;

		/**** �ؼ�����ʾ���ı� ****/
		LPTSTR text = new wchar_t[1024];

		/**** �ؼ���ʾ���ı��߶� ****/
		int size = 16;

		/**** �ؼ��Ƿ�ɼ����ɼ�Ϊtrue������Ϊfalse ****/
		bool visible = false;

		/**** ���캯������ʼ���ؼ����Ͻǵ����ꡢ��ʾ���ı����ı��ĸ߶ȣ�Ĭ��Ϊ16�� ****/
		Label(int x, int y, LPCTSTR text, int size = 16) {
			this->x = x;
			this->y = y;
			lstrcpy(this->text, text);
			this->size = size;
			width = 0;
			height = 0;
			return;
		}

		/**** ��ʾ�ؼ�,�ɹ�����true�������쳣����false ****/
		bool show() {
			if (visible) {
				//��ǰ�ؼ��ɼ�
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

		/**** ���ؿؼ� ****/
		void hide() {
			clearrectangle(x, y, x + width - 1, y + height - 1);
			visible = false;
			return;
		}

		/**** ˢ�²������ʾ״̬�£� ****/
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

	/**** ��ѡ�򣨸ÿؼ�Ϊ�Զ���С�� ****/
	class CheckBox {
	private:
		//��ѡ��=��ť+�ı�
		Button* button;
		Label* label;

	public:
		/**** �ؼ����Ͻǵ�x���� ****/
		int x = 0,

			/**** �ؼ����Ͻǵ�y���� ****/
			y = 0;

		/**** �ؼ�����ʾ���ı� ****/
		LPTSTR text = new wchar_t[1024];

		/**** �Ƿ��ѱ���ѡ ****/
		bool state = false;

		/**** ���캯������ʼ���ؼ����Ͻǵ���������ʾ���ı� ****/
		CheckBox(int x, int y, LPCTSTR text) {
			this->x = x;
			this->y = y;
			lstrcpy(this->text, text);
			button = new Button(x, y, 18, 18, L"");
			label = new Label(x + 20, y, text, 18);
			return;
		}

		/**** ��ʾ�ؼ�,�ɹ�����true�������쳣����false ****/
		bool show() {
			if (!button->show() || !label->show()) {
				//��ǰ�ؼ����ܿɼ�
				hide();
				return false;
			}
			return true;
		}

		/**** ���ؿؼ� ****/
		void hide() {
			button->hide();
			label->hide();
			return;
		}

		/**** �ؼ��Ƿ񱻹�ѡ���������л�Ч���������쳣����false ****/
		bool check(ExMessage m) {
			if (!(button->visible && label->visible)) {
				//��ǰ�ؼ����ɼ�
				return false;
			}
			if (button->click(m)) {
				state = !state;
				state ? lstrcpy(button->text, L"��") : lstrcpy(button->text, L"");
				reload();
			}
			return true;
		}

		/**** ˢ�²������ʾ״̬�£� ****/
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

	/**** ��ѡ�����15��ÿؼ�Ϊ�Զ���С�� ****/
	class CheckedListBox {
	private:
		int num = 0;

	public:
		//��ѡ��=�����ѡ��
		CheckBox* checkbox[15] = { nullptr };

		/**** �ؼ����Ͻǵ�x���� ****/
		int x = 0,

			/**** �ؼ����Ͻǵ�y���� ****/
			y = 0;

		/**** ���캯������ʼ���ؼ����Ͻǵ���������ʾ���ı� ****/
		CheckedListBox(int x, int y, int num, LPCTSTR text[]) {
			this->x = x;
			this->y = y;
			if (num > 15) {
				MessageBox(0, L"�������࣡", L"UI.h", MB_OK | MB_ICONSTOP);
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
				MessageBox(0, L"�������࣡", L"UI.h", MB_OK | MB_ICONSTOP);
				return;
			}
			this->num = num;
			for (int i = 0; i < num; i++) {
				this->checkbox[i] = &checkbox[i];
			}
		}

		/**** ��ʾ�ؼ�,�ɹ�����true�������쳣����false ****/
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

		/**** ���ؿؼ� ****/
		void hide() {
			for (int i = 0; i < num; i++) checkbox[i]->hide();
			return;
		}

		/**** �ؼ��Ƿ񱻹�ѡ���������л�Ч���������쳣����false ****/
		bool check(ExMessage m) {
			for (int i = 0; i < num; i++) {
				if (!checkbox[i]->check(m))return false;
			}
			return true;
		}

		/**** ˢ�²������ʾ״̬�£� ****/
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

	/**** �ı��� ****/
	class TextBox {
	private:
		int width, height = 22;
		Button* button;
		Label* label;

	public:
		/**** �ؼ����Ͻǵ�x���� ****/
		int x = 0,

			/**** �ؼ����Ͻǵ�y���� ****/
			y = 0;

		/**** �ؼ�����ʾ���ı� ****/
		LPTSTR text = new wchar_t[1024];

		/**** ���캯������ʼ���ؼ����Ͻǵ���������ʾ���ı� ****/
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

		/**** ��ʾ�ؼ�,�ɹ�����true�������쳣����false ****/
		bool show() {
			if (!button->show() || !label->show()) {
				hide();
				return false;
			}
			return true;
		}

		/**** ���ؿؼ� ****/
		void hide() {
			button->hide();
			label->hide();
			return;
		}

		/**** ˢ�²������ʾ״̬�£� ****/
		void reload() {
			button->reload();
			label->reload();
			return;
		}

		/**** �����ı� ****/
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
#error ����ûװeasyx��~
#endif
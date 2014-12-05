#include <stdlib.h>

#include "ui.h"
#include "ui_input.h"


struct input *
init_input(bool box, bool shadow, char *prompt, size_t input_len)
{
  struct input *a = calloc(1, sizeof(struct input));

  a->box = box;
  a->shadow = shadow;
  a->input = calloc(input_len+1, sizeof(char));
  a->input_len = input_len;
  a->prompt = prompt;
  return (a);
}

void
free_input(struct input *a)
{
  if (a->input != NULL) {
    free(a->input);
  }
  free(a);
}

int
input_cb(WINDOW *win, void *data, bool needs_update)
{
  struct input *a = (struct input *) data;

  if (a == NULL) return (UICB_ERR_UNDEF);
mvaddch(7,1,'A');
wrefresh(win);
refresh();
  return (UICB_OK);
}

void
register_input(unsigned int x, unsigned int y, unsigned int width, unsigned int height, struct input *a, chtype attr)
{
  WINDOW *wnd = newwin(height, width, y, x);
  box(wnd, 0, 0);
wrefresh(wnd);
  register_ui_elt(input_cb, (void *) a, wnd, attr);
}

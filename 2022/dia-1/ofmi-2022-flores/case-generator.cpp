#include <fstream>
#include <random>
#include <set>

#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)

const int MAX_X = 1e5;
const int MAX_Y = 1e5;

typedef std::pair<int, int> pii;
typedef std::string string;

double rand_double(std::pair<double, double> limit) {
  static std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(limit.F, limit.S);
  return dis(gen);
}

int rand_int(pii limit) {
  static std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(limit.F, limit.S);
  return dis(gen);
}

class CaseBuilder {
  string case_name;
  double no_limit_rate;
  int n, m;
  int x_start, y_start, x_end, y_end;
  int max_length;
  pii limit_x, limit_y;
  bool place_position_aside = false;
  bool place_aside_start;
  bool place_aside_end;

 public:
  CaseBuilder(string name) { this->case_name = name; }

  CaseBuilder set_no_limit_rate(double d) {
    no_limit_rate = d + 1e-5;
    return *this;
  }
  CaseBuilder set_n_m(pii p) {
    n = p.F, m = p.S;
    return *this;
  }
  CaseBuilder set_start(pii p) {
    x_start = p.F, y_start = p.S;
    return *this;
  }
  CaseBuilder set_end(pii p) {
    x_end = p.F, y_end = p.S;
    return *this;
  }
  CaseBuilder set_max_length(int limit_grow) {
    max_length = limit_grow;
    return *this;
  }
  CaseBuilder set_limit_x(pii p) {
    limit_x = p;
    return *this;
  }
  CaseBuilder set_limit_y(pii p) {
    limit_y = p;
    return *this;
  }
  CaseBuilder set_place_position_aside(bool place_position) {
    place_position_aside = place_position;
    if (rand_double({0, 1}) < 0.5) {
      place_aside_start = true;
    } else {
      place_aside_start = false;
    }
    return *this;
  }

  string rand_build() {
    string file_name = case_name + ".in";
    std::ofstream output(file_name);

    output << n << " " << m << "\n";
    output << x_start << " " << y_start << "\n";
    output << x_end << " " << y_end << "\n";

    std::set<std::pair<int, int>> flowers;
    forn(i, n) {
      int x, y;
      do {
        x = rand_int(limit_x);
        y = rand_int(limit_y);
        if (place_position_aside) {
          // x start
          x = ((x - x_start) / m) * m + x_start;
          if (x < x_start) {
            --x;
          } else {
            ++x;
          }

          // y start
          y = ((y - y_start) / m) * m + y_start;
          if (y < y_start) {
            --y;
          } else {
            ++y;
          }
        }
      } while (flowers.count({x, y}) == 1);
      flowers.insert({x, y});
      output << x << " " << y << "\n";
    }

    forn(i, n) {
      int length;
      if (rand_double({0, 1}) < no_limit_rate)
        length = -1;
      else
        length = rand_int({max_length / 3, max_length});
      output << length << "\n";
    }

    output.flush();
    output.close();
    return file_name;
  }
};

void sub1(int casos) {
  forn(i, casos) {
    pii start = {rand_int({0, 100}), rand_int({0, 100})};
    pii end = {rand_int({0, 100}), rand_int({0, 100})};

    CaseBuilder builder("sub1_" + std::to_string(i));
    builder.set_no_limit_rate(rand_double({0, 0.2}))
        .set_max_length(20)
        .set_n_m({rand_int({1, 10}), rand_int({1, 5})})
        .set_start(start)
        .set_end(end)
        .set_limit_x({0, 100})
        .set_limit_y({0, 100})
        .set_place_position_aside(i >= casos * 0.7)
        .rand_build();
  }
}

void sub2(int casos) {
  forn(i, casos) {
    pii start = {rand_int({-MAX_X, MAX_X}), 0};
    pii end = {rand_int({-MAX_X, MAX_X}), 0};

    CaseBuilder builder("sub2_" + std::to_string(i));
    builder.set_no_limit_rate(rand_double({0, 0.25}))
        .set_max_length(2e5)
        .set_n_m({rand_int({1, 500}), rand_int({1, 10000})})
        .set_start(start)
        .set_end(end)
        .set_limit_x({-MAX_X, MAX_X})
        .set_limit_y({0, 0})
        .rand_build();
  }
}

void sub3(int casos) {
  forn(i, casos) {
    pii start = {rand_int({-MAX_X, MAX_X}), rand_int({-MAX_Y, MAX_Y})};
    pii end = {rand_int({-MAX_X, MAX_X}), rand_int({-MAX_Y, MAX_Y})};

    CaseBuilder builder("sub3." + std::to_string(i));
    builder.set_no_limit_rate(1)
        .set_n_m({rand_int({1, 1000}), rand_int({1, 10000})})
        .set_start(start)
        .set_end(end)
        .set_limit_x({-MAX_X, MAX_X})
        .set_limit_y({-MAX_Y, MAX_Y})
        .set_place_position_aside(i >= casos * 0.7)
        .rand_build();
  }
}

void sub_3_alreves(int casos) {
  forn(i, casos) {
    pii start = {rand_int({-MAX_X, MAX_X}), rand_int({-MAX_Y, MAX_Y})};
    pii end = {rand_int({-MAX_X, MAX_X}), rand_int({-MAX_Y, MAX_Y})};

    CaseBuilder builder("esp." + std::to_string(i));
    builder.set_no_limit_rate(0)
        .set_max_length(2e5)
        .set_n_m({rand_int({1, 1000}), rand_int({1, 10000})})
        .set_start(start)
        .set_end(end)
        .set_limit_x({-MAX_X, MAX_X})
        .set_limit_y({-MAX_Y, MAX_Y})
        .set_place_position_aside(i >= casos * 0.7)
        .rand_build();
  }
}

void normal(int casos) {
  forn(i, casos) {
    pii start = {rand_int({-MAX_X, MAX_X}), rand_int({-MAX_Y, MAX_Y})};
    pii end = {rand_int({-MAX_X, MAX_X}), rand_int({-MAX_Y, MAX_Y})};

    CaseBuilder builder("normal." + std::to_string(i));
    builder.set_no_limit_rate(rand_double({0, 0.15}))
        .set_max_length(2e5)
        .set_n_m({rand_int({1, 1000}), rand_int({1, 1e5})})
        .set_start(start)
        .set_end(end)
        .set_limit_x({-MAX_X, MAX_X})
        .set_limit_y({-MAX_Y, MAX_Y})
        .set_place_position_aside(i >= casos * 0.7)
        .rand_build();
  }
}

int main() {
  sub1(10);
  sub2(15);
  sub3(10);
  sub_3_alreves(10);
  normal(15);
  return 0;
}

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: lib/convolution/Convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"lib/convolution/Convolution.hpp\"\n#include \"lib/math/ModInt/mint.hpp\"\n\
    \nusing mint = akTARDIGRADE13::mint<998244353>;\n\n#include <iostream>\n\nint\
    \ main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint> a(n),\
    \ b(m);\n    for(int i = 0; i < n; ++i) std::cin >> a[i];\n    for(int i = 0;\
    \ i < m; ++i) std::cin >> b[i];\n    akTARDIGRADE13::NTT<998244353> convolution;\n\
    \    auto c = convolution.multiply(a, b);\n    for(int i = 0; i < n + m - 1; ++i)\
    \ {\n        std::cout << c[i] << \" \\n\"[i == n + m - 2];\n    }\n\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution/convolution/yosupo_convolution_mod.test.cpp
- /verify/verify/convolution/convolution/yosupo_convolution_mod.test.cpp.html
title: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
---

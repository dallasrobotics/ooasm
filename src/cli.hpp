#pragma once

namespace ooasm{

  namespace cli{

    using namespace xtd::parse;

    namespace _{
      STRING(szOutput, "--output=");
      STRING(szInput, "--input=");
      REGEX(szPath, "(^([a-z]|[A-Z]):(?=\\\\(?![\\0-\\37<>:\"/\\\\|?*])|\\/(?![\\0-\\37<>:\"/\\\\|?*])|$)|^\\\\(?=[\\\\\\/][^\\0-\\37<>:\"/\\\\|?*]+)|^(?=(\\\\|\\/)$)|^\\.(?=(\\\\|\\/)$)|^\\.\\.(?=(\\\\|\\/)$)|^(?=(\\\\|\\/)[^\\0-\\37<>:\"/\\\\|?*]+)|^\\.(?=(\\\\|\\/)[^\\0-\\37<>:\"/\\\\|?*]+)|^\\.\\.(?=(\\\\|\\/)[^\\0-\\37<>:\"/\\\\|?*]+))((\\\\|\\/)[^\\0-\\37<>:\"/\\\\|?*]+|(\\\\|\\/)$)*()$");
    }

    using WS = whitespace<'\t', '\n', '\r'>;

    struct file_path : rule<file_path, _::szPath>{
      template <typename ..._argTs> file_path(_argTs&&...oArgs) : rule(std::forward<_argTs>(oArgs)...){}
    };

    struct output_switch : rule<output_switch, and_<_::szOutput, file_path> >{
      template <typename ..._argTs> output_switch(_argTs&&...oArgs) : rule(std::forward<_argTs>(oArgs)...){}
    };

    struct input_switch : rule<input_switch, and_<_::szInput, file_path> >{
      template <typename ..._argTs> input_switch(_argTs&&...oArgs) : rule(std::forward<_argTs>(oArgs)...){}
    };

    struct cmdline : rule<cmdline, and_<output_switch, input_switch> >{
      template <typename ..._argTs> cmdline(_argTs&&...oArgs) : rule(std::forward<_argTs>(oArgs)...){}
    };

  }

}
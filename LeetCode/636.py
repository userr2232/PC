class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        callstack = []
        f_times = dict()
        idle_times = dict()
        for log in logs:
            f_id, f_type, t = log.split(":")
            t = int(t)
            if f_type == "start":
                callstack.append(log + f":{len(callstack)}")
                continue
            else:
                ending_f_id, ending_f_type, ending_f_start_t, ending_f_level = callstack[-1].split(":")
                ending_f_start_t, ending_f_level = int(ending_f_start_t), int(ending_f_level)
                callstack = callstack[:-1]
                tmp = t - ending_f_start_t + 1
                reduction = idle_times[len(callstack) + 1] if idle_times.get(len(callstack) + 1) else 0
                if f_times.get(ending_f_id):
                    f_times[ending_f_id] += tmp - reduction
                else:
                    f_times[ending_f_id] = tmp - reduction
                idle_times[len(callstack) + 1] = 0
                if idle_times.get(len(callstack)):
                    idle_times[len(callstack)] += tmp
                else:
                    idle_times[len(callstack)] = tmp
        return [f_times[str(i)] for i in range(n)]